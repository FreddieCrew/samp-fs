#define RUN_TESTS

#include <a_samp> // https://github.com/pawn-lang/samp-stdlib
#include <filesystem>
#include <YSI_Core/y_testing> // https://github.com/pawn-lang/YSI-Includes

main() {
    print("Testing...");
}

Test:CheckExists() {
    ASSERT(fs_dexists("dir"));
    ASSERT(fs_fexists("dir/hello.txt"));
}

Test:Dir() {
    new const dir[] = "dir/test";

    if (fs_dexists(dir)) {
        ASSERT(fs_deldir(dir) == 1);
    }

    new retval = fs_createdir(dir);

    ASSERT(retval == 1);
    ASSERT(fs_dexists(dir));
    ASSERT(fs_deldir(dir) == 1);
}

Test:DelDir() {
    new const dir[] = "dir/testr";

    if (!fs_dexists(dir)) {
        ASSERT(fs_createdir(dir) == 1);
    }

    new retval = fs_deldir(dir);
    ASSERT(retval == 1);
    ASSERT(fs_dexists(dir) == true);
}

Test:MovF() {
    new const from[] = "dir/fileA";
    new const to[] = "dir/fileB";

    if (!fs_fexists(from)) {
        fclose(fopen("fileA", io_write));
    } else if (fs_fexists(from)) {
        fremove("fileB");
    }

    new retval = fs_fmove(from, to);
    ASSERT(retval == 1);
    ASSERT(fs_fexists(to));
    ASSERT(!fs_fexists(from));

    fremove("fileB");
}

Test:CopyF() {
    new const from[] = "fileC";
    new const to[] = "fileD";

    if (!fs_fexists(from)) {
        fclose(fopen("fileC", io_write));
    } else if (fs_fexists(from)) {
        fremove("fileD");
    }

    new retval = fs_fcopy(from, to);
    ASSERT(retval == 1);
    ASSERT(fs_fexists(to));
    ASSERT(fs_fexists(from));

    fremove("fileC"), fremove("fileD");
}
