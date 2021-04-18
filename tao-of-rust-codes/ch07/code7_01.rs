#[derive(Debug, Copy, Clone)]
struct Book<'a> {
    name: &'a str,
    isbn: i32,
    version: i32,
}

fn main() {
    let book1 = Book {
        name: "Rust program language",
        isbn: 20181212,
        version: 1,
    };

    let book2 = Book {
        version: 2,
        ..book1
    };

    println!("{:?}", book1);
    println!("{:?}", book2);
}