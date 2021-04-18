use std::panic;

fn sum(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    let result = panic::catch_unwind(|| {
        println!("hello!");
    });

    println!("{:?}", result.is_ok());

    let result = panic::catch_unwind(|| {
        panic!("oh no!");
    });

    println!("{:?}", result.is_err());

    println!("{:?}", sum(1, 2));
}