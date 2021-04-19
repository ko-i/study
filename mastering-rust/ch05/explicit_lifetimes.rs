fn foo<'a>(a: &'a str, b: &'a str) -> &'a str {
    b
}

fn main() {
    let a = "Hello";
    let b = "World";
    let c = foo(a, b);
}