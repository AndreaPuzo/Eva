# Eva
#### Eva ecosystem - launch base for future languages
Welcome to the Eva ecosystem, I'm Andrea and, if you want, I'll take you inside hand in hand of this crazy but at the same time very fun and educational project.

### What is the purpose?
Eva was born with the aim of creating an ecosystem to help those who have the desire to give birth to its own programming language, even just for fun.

```
# ugo (language) implemented using Eva ecosystem
# eva{ 'dory' }

println{ 'Welcome to ugo!' }

for , # infinite loop
  src : input{ '>>> _\b', str }
  
  if src = 'quit'
    break
  
  if src.iseq{ 'say', 3 }
    src : src + 3
    
    if src[ 0 ] = ' '
      src : src + 1
      println{ src }
    else
      println{ 'error: missing argument for \'say\'' }
  else
    x : nat{ src, @src }
    if src[ 0 ] = '!' # do factorial
      println{ str{ x } + '! = ' + str{ fact{ x } } }
    else
      println{ 'error: invalid operation' }

# recursive factorial
rfact := { x : nat } -> { y : nat }
  if x = 0 or x = 1
    ret 1
  else
    y : x * rfact{ x - 1 }

# basic factorial
fact := { x : nat } -> { y : nat }
  y : 1
  for i in [1;x], i : i + 1
    y : y * i

println{ str{ rfact{ 5 } = fact{ 5 } } + '\n' }
println{ str{ } }

# use Eva ecosystem inside your language

path : input{ 'image path: ', str }
path : path + '/' + input{ 'image name: ', str }
len : nat
img : read_from_file{ path, @len }
eva.init{ }
eva.load_image{ img, len }
res : eva.start{ 120 }
eva.clear{ }
println{ '[result] ' + str{ res } }

```

Cooming soon...
