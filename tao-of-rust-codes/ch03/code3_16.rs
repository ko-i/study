fn foo<T>(x: T) -> T {
    x
}

fn main() {
    assert_eq!(foo(1), 1);
    assert_eq!(foo("hello"), "hello");
}