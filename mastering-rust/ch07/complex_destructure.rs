enum Foo {
    One, Two, Three
}

enum Bar(Foo);

struct Dummy {
    inner: Bar
}

struct ComplexStruct {
    obj: Dummy
}

fn get_complex_struct() -> ComplexStruct {
    ComplexStruct {
        obj: Dummy {
            inner: Bar(Foo::Three)
        }
    }
}

fn main() {
    let a = get_complex_struct();
}