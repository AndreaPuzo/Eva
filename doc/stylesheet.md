## Common
```
<tab> := spaces = 2
```

#### if, else if, else
```c
if (<condition>) {
<tab><body>
} [(else if (<condition>) {
<tab><body>
})+] [else {
<tab><body>
}]
```

#### switch
```c
switch (<object>) {
<tab>case <value>[ +]: {
<tab><tab><body>
<tab>} break;

...

<tab>default: {
<tab><tab><body>
<tab>} break;
}
```

#### while loop
```c
while (<condition>) {
<tab><body>
}
```
  
#### do-while loop
```c
do {
<tab><body>
} while (<condition>);
```

#### infinite loop
```c
for (;;) {
<tab><body>
}
```

## Eva API
#### functions
```c
// declaration
__EVA_API [ +]<return-type> [ +]eva_<identifier>[ +](<arguments>)[ +];

// definition
__EVA_API <return-type> eva_<identifier>(<arguments>)
{
<tab><body>
}
```

#### constants
```c
// preprocesseor
#[ +]define EVA_<IDENTIFIER> [ +]<value>

// C constant
// -- declaration
__EVA_API const <type> [ +]EVA_<IDENTIFIER> [ +];
// -- definition
const <type> EVA_<IDENTIFIER> = <value>;
```

## Generic Identifiers

```c
// future parameters
input: i_<identifier>
constant input: i_<IDENTIFIER>
output: o_<identifier>
input/output: io_<identifier>
```

