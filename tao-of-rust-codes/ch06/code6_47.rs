fn square() -> Box<dyn Fn(i32) -> i32> {
    Box::new(|i| i * i)
}

fn main() {
    let square = square();

    println!("{:?}", square(1));
    println!("{:?}", square(2));
}