[![Build Status](https://travis-ci.org/bonewell/moneybox.svg?branch=develop)](https://travis-ci.org/bonewell/moneybox)

# Prepare
## Install mongoDB 4.0
[docs.mongodb.com/manual](https://docs.mongodb.com/manual/administration/install-community/)

# Build
```Shell
conan remote add public-conan https://api.bintray.com/conan/bincrafters/public-conan True
mkdir build
cd build
conan install ..
cmake ..
cmake -build .
```

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
    
        "id": <number>,
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
