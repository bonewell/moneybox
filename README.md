# Build
```Shell
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
    "result": <number>
}
```
