# Eva
#### Eva ecosystem - launch base for future languages
Welcome to the Eva ecosystem, I'm Andrea and, if you want, I'll take you inside hand in hand of this crazy but at the same time very fun and educational project.

### What is the purpose?
Eva was born with the aim of creating an ecosystem to help those who have the desire to give birth to its own programming language, even just for fun.

Let's imagine we want to generate a language called 'X' with a simple syntax, like the following:
```
# Types:
# nat -> natural number  (N)
# int -> integer number  (Z)
# rat -> rational number (Q)
# str -> string

# Builtins
# input   := { msg: str, type: typ } -> { typ }
# print   := { msg: str } -> {}
# println := { msg: str } -> {}
# nat     := { x: typ } -> { nat }
# int     := { x: typ } -> { int }
# rat     := { x: typ } -> { rat }
# str     := { x: typ } -> { str }
# abs     := { x: nat|int|rat } -> { x }
# format  := { fmt: str, args: {} of typ } -> { str }

x: input('give me a number: _\b', int)
s: 'X lang!\n'          # I am a comment
print(str(x) + ' ' + s) # I am another comment!

if x % 2 = 0
  println('even')
else
  println('odd')

fact := { a: nat } -> { b: nat } {
  if a = 0 or a = 1
    b: 1
  else
    b: a * fact(a - 1)
}

x: nat(abs(x))
y: fact(x)
println(str(x) + '! = ' + str(y))

doSomething := { a,b: nat, c: rat, d: @str } -> {} {
  [d]: [d] + str(a + b) + ', ' str(c) '\n' # [<something>] deferences <something>
}

s: make(str) # create a dynamic string
doSomething(x, y, 1.0 / 137, @s) # @ means 'address of'
print(s)

# arrays, typedef, methods

Vec2 := typ {} of 2 rat
ori: Vec2 { 0,0 }

norm := { v: Vec2 }.{} -> { n: nat } {
  n: sqrt( v[0] ^ 2 + v[1] ^ 2 )
}

normalize := { v: @Vec2 }.{} -> {} {
  a: [v].norm()
  [v][0]: [v][0] / a
  [v][1]: [v][1] / a
}

# structures

Car := typ {
  model  : 'Fiat'|'Tesla'|'Renault' # enumeration of strings
  driver : @Driver                  # pointer to a type Driver
}

Driver := typ {
  age        : nat in [18;99] # natural in range
  first_name : str of 5       # constant string
  last_name  : str            # dynamic string
}

Alice  : Driver{ 22, 'Alice', 'Wilson' }
Andrea : Driver{ 19, 'Andrea', 'Puzo' }    # 'Andrea' will be trucated in 'Andre' (str of 5)
Geppo  : Driver{ 100, '#', str of 50 '#' } # error: Driver.age out of range

DF876XG : Car{ 'Tesla', @Alice }
DZ781XY : Car{ 'Fiat', @Andrea }

(DF876XG, DZ781XY)

```

Cooming soon...
