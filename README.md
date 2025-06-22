# UEB-Testsuite
A student created testsuite for the [Übersetzterbau (Compilers)](https://tiss.tuwien.ac.at/course/educationDetails.xhtml?dswid=7084&dsrid=741&semester=2025S&courseNr=185A48) VU at [TU Wien](https://www.tuwien.at/en/) in 2025S.

[Previous year's test suite](https://github.com/AntiKippi/UEB-Testsuite-2024S)

## Usage
1. `git clone https://github.com/MordJunior/complang.git ~/test`
2. The tests starting from the "scanner" example should be picked up automatically from the test scripts on the server

## Tips
With the following optional convenience function added to your `.bashrc` you can run the test suite by executing `runtest <exercise> <exercise> ...`.
If you want to run all tests just execute `runtest`. There are two flags available with the function:
- `-s / --short` only outputs the last 5 lines that show how many tests were successful. 
- `-p / --pause` waits after every test that was executed for user input (only useful when executing more than one test).

```bash
function runtest() {
        OPT=$(getopt -o 'sp' -l 'short,pause' -n 'runtest' -- "$@")
        if [ $? -ne 0 ]; then
                echo "Usage: $1 [-s/--short] [-p/--pause] [test1, test2, ...]" >&2
                return 1
        fi

        eval set -- "$OPT"
        unset OPT

        SHORT=0
        PAUSE=0

        while true; do
                case "$1" in
                        '-s'|'--short')
                                SHORT=1
                                shift
                                continue
                                ;;
                        '-p'|'--pause')
                                PAUSE=1
                                shift
                                continue
                                ;;
                        '--')
                                shift
                                break
                                ;;
                        *)
                                echo "Unrecognised option $1" >&2
                                return 1
                                ;;
                esac
        done

        TARGETS="$@"

        if [[ $# -eq 0 ]]; then
                echo "no args provided runing all tests"
                TARGETS="asma asmb scanner parser ag codea codeb gesamt"
        fi

        if [ -d "~/test" ]; then
                echo "could not find test directory. Only running provided tests"
        else
                git -C ~/test pull
        fi

        for target in $TARGETS; do
                echo
                echo "Running tests for $target"
                if [ $SHORT ]; then
                        "/usr/ftp/pub/ubvl/test/${target}/test" 2>/dev/null | tail -n5
                else
                        "/usr/ftp/pub/ubvl/test/${target}/test"
                fi
                if [ $PAUSE ]; then
                        echo
                        read -p "Press Enter to continue to the next test"
                fi
        done
}
```

## Notes
- If you write your own tests, please share them by creating a pull request
- If you choose to do so please use the following naming convention to avoid conflicts: `{username}_{description}.{type}` (e.g. `AntiKippi_comments.0`)
