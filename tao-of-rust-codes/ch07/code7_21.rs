struct PrintDrop (&'static str);

impl Drop for PrintDrop {
    fn drop(&mut self) {
        println!("Dropping {}", self.0)
    }
}

enum E {
    Foo(PrintDrop, PrintDrop)
}

struct Foo {
    x: PrintDrop,
    y: PrintDrop,
    z: PrintDrop,
}

fn main() {
    // let x = PrintDrop("x");
    // let y = PrintDrop("y");

    // let tup1 = (PrintDrop("a"), PrintDrop("b"), PrintDrop("c"));
    // let tup2 = (PrintDrop("x"), PrintDrop("y"), PrintDrop("z"));

    // let tup1 = (PrintDrop("a"), PrintDrop("b"), PrintDrop("c"));
    // let tup2 = (PrintDrop("x"), PrintDrop("y"), panic!());

    /*
    let e = E::Foo(PrintDrop("a"), PrintDrop("b"));
    let f = Foo {
        x: PrintDrop("x"),
        y: PrintDrop("y"),
        z: PrintDrop("z"),
    };
    */

    /*
    let z = PrintDrop("z");
    let x = PrintDrop("x");
    let y = PrintDrop("y");

    let closure = move || {y; z; x;};
    */

    let y = PrintDrop("y");
    let x = PrintDrop("x");
    let z = PrintDrop("z");

    let closure = move || {
        {
            let z_ref = &z;
        }

        x;
        y;
        z;
    };
}