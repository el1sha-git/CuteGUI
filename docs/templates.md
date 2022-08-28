# File structure
### File sections

> #### 1. template
> > This section have html5 code and some. Strict html5 standard, but possible have custom framework features not conflicted with html5 standart
> #### 2. style
> > Have a styles for template. Support css/scss/sass maybe less(?)
> #### 3. logic
> > Have logic for this template. Interpreted as c++ code exclude 'import from' derictive!

### Logic secion

This section contain c++ code. The exception is 'import from' derective. That used to include component to screen.

```c++
<template>
    <p onclick="changeTextThroughEl()">{{ str }}</p>
    <p onclick="changeTextThroughLink()">{{ str }}</p>
</template>

<style lang="css">

</style>
// Used for include components(Special logic)
//
import 'Navbar' from "@/components/navbar.cg"

#include <string>

// This variable will be substituted to template like a link to str
std::string str = "Hello world!";


void changeTextThroughEl(){
    this.text = "Change text through element method"
}

void changeTextThroughLink(){
    str = "Change text through str variable"
}
```