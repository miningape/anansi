# anansi 
A programming language aiming to replicate some of JS and Python, but it runs like Lua so it can be used as a scripting language for larger applications

The name is probably going to change: alternatives: Sol, Solis, Apricus

## design
semi-colon or newline terminated. Comments are done with // or /**/

```anansi
let x = 10
let y: int = 10
x = "Hello World!" // This would be ok
y = "Hello World!" // This is not ok
```
Variable declarations are done with let, if type is not specified it becomes a generic type. This means it isn't subject to specific rules and can be modified with any data,
however this takes more space in memory. Specifying a type is exactly like in C where it allocates that block of memory as that type, its more efficient and allows for direct
control.

```anansi
fn foo( x, y: int ) {
  let bar = x
  return bar
}
```
Functions will not have a specified return type. 

```anansi
if (cond) {} elseif {} else {}
while (cond) {}
do {} while (cond)
for ( dec; cond; inc ) {}
switch ( foo ) {
  case bar:
    break
  default:
    break
}
```
All the things you would expect

```anansi
import file.anc

fn main () {}
```

I want it to be very interactive with the code that is running it
```C
int main() {
  void* interpreter = anansi();
  interpreter.load( file.anc );
  void* anan = interpreter.poll( "varname" );
  interpreter.run() ;
}
```
