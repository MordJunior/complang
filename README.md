# UEB-Testsuite
A student created testsuite for the [Übersetzterbau (Compilers)](https://tiss.tuwien.ac.at/course/educationDetails.xhtml?dswid=7084&dsrid=741&semester=2025S&courseNr=185A48) VU at [TU Wien](https://www.tuwien.at/en/) in 2025S.

[Previous year's test suite](https://github.com/AntiKippi/UEB-Testsuite-2024S)

## Usage
1. `git clone https://github.com/MordJunior/complang.git ~/test`
2. The tests starting from the "scanner" example should be picked up automatically from the test scripts on the server

## Tips
With the following optional convenience function added to your `.bashrc` you can run the test suite by executing `runtest <exercise>` or simply `runtest` if you are in the directory you want to test:
```bash
function runtest() {
    target="$1"
    if [ -z "$target" ]; then
        target="$(basename "$PWD")"
    fi
    git -C ~/test pull && "/usr/ftp/pub/ubvl/test/${target}/test"
}
```

### Better test function for multiple tests

If you want to be able to run multiple test suites at once, you can use the following functions. It will run all test scripts you give it as arguments. It will wait for a keypress after each test, so you can check the output before moving on to the next one.

```bash
function runtest() {
    if [ "$#" -eq 0 ]; then
        set -- "$(basename "$PWD")"
    fi

    local i=0
    local total=$#

    for target in "$@"; do
        ((i++))
        if [ -d ~/test ]; then
            git -C ~/test pull && "/usr/ftp/pub/ubvl/test/${target}/test"
        else
            echo "Could not find ~/test directory, only running provided tests"
            "/usr/ftp/pub/ubvl/test/${target}/test"
        fi

        if [ "$i" -lt "$total" ]; then
            echo
            read -p "Press Enter to continue to the next test (completed $i/$total)..."
        fi
    done
}
```

## Notes
- If you write your own tests, please share them by creating a pull request
- If you choose to do so please use the following naming convention to avoid conflicts: `{username}_{description}.{type}` (e.g. `AntiKippi_comments.0`)
