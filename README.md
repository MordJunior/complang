# UEB-Testsuite
A student created testsuite for the [Übersetzterbau (Compilers)](https://tiss.tuwien.ac.at/course/educationDetails.xhtml?dswid=7084&dsrid=741&semester=2025S&courseNr=185A48) VU at [TU Wien](https://www.tuwien.at/en/) in 2025S.

[Previous year's test suite](https://github.com/AntiKippi/UEB-Testsuite-2024S)

## Usage
1. `git clone https://github.com/MordJunior/complang.git ~/test`
2. The tests starting from the "scanner" example should be picked up automatically from the test scripts on the server

## Tips
With the following optional convenience function added to your `.bashrc` you can run the test suite by executing `runtest <exercise>` or simply `runtest` if you are in the directory you want to test:
```
function runtest() {
    target="$1"
    if [ -z "$target" ]; then
        target="$(basename "$PWD")"
    fi
    git -C ~/test pull && "/usr/ftp/pub/ubvl/test/${target}/test"
}
```

## Notes
- If you write your own tests, please share them by creating a pull request
- If you choose to do so please use the following naming convention to avoid conflicts: `{username}_{description}.{type}` (e.g. `AntiKippi_comments.0`)
