fn square() -> Box<dyn FnOnce(i32) -> i32> {
    Box::new(|i| i * i)
}

fn main() {
    let square = square();

    println!("{:?}", square(2));
    // println!("{:?}", square(2));
}