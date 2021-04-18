use std::fmt::Display;

struct Foo<T: Display> {
    bar: T
}

struct Bar<F> where F: Display {
    inner: F
}

fn main() {
    
}