fn square() -> impl FnOnce(i32) -> i32 {
    |i| { i * i }
}

fn main() {
    let square = square();

    println!("{:?}", square(2));
}