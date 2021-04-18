trait Foo {
    fn bad<T>(&self, x: T);
    fn new() -> Self;
}

trait Foo {
    fn bad<T>(&self, x: T);
}

trait Foo: Bar {
    fn new() -> Self;
}

trait Foo {
    fn bad<T>(&self, x: T);
    fn new() -> Self where Self: Sized;
}