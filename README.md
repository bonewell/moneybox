```Shell
mkdir build
cd build
conan install ..
cmake ..
cmake -build .
```

# Protocol

/amount - ₽
in:
{
    "user": <string>
}
out:
{
    "amount": <number>
}

/transfer - The list of transfers
in:
{
    "user": <string>
}
out:
[
{
    "id": <number>,
    "sender": <string>
    "recipient": <string>,
    "amount": <number>,
    "description": <string>
},
...
]

/transfer/send - Send money
in:
{
    "user": <string>
    "recipient": <string>,
    "amount": <number>,
    "description": <string>
}
out:
{
    "result": <int>
}
