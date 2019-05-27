[![Build Status](https://travis-ci.org/bonewell/moneybox.svg?branch=develop)](https://travis-ci.org/bonewell/moneybox)
[![Coverage Status](https://coveralls.io/repos/github/bonewell/moneybox/badge.svg?branch=develop)](https://coveralls.io/github/bonewell/moneybox?branch=develop)

# Prepare
## Install mongoDB 4.0
[docs.mongodb.com/manual](https://docs.mongodb.com/manual/administration/install-community/)

# Build
```Shell
conan remote add stiffstream https://api.bintray.com/conan/stiffstream/public True
conan remote add public-conan https://api.bintray.com/conan/bincrafters/public-conan True
mkdir build
cd build
conan install ..
cmake ..
cmake -build .
```

# Run
## Run server
```Shell
./bin/moneybox
```

## Run UI
Open `index.html` in browser

# Protocol

#### Get balance of the account ₽
/amount

in:
```json
{
    "user": <string>
}
```
out:
```json
{
    "amount": <number>
}
```

#### Get list of transfers
/transfer

in:
```json
{
    "user": <string>
}
```
out:
```json
[
    {
        "sender": <string>,
        "recipient": <string>,
        "amount": <number>,
        "description": <string>
    },
...
]
```

#### Send money
/transfer/send

in:
```json
{
    "user": <string>,
    "recipient": <string>,
    "amount": <number>,
    "description": <string>
}
```
out:
```json
{
    "result": <boolean>
}
```

# UML
[moneybox/wiki](https://github.com/bonewell/moneybox/wiki)
