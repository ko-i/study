use std::ops::Mul;

fn square<T: Mul<T, Output = T>>(x: T, y: T) -> T {
    x * y
}

fn main() {
    let a = square::<u32>(37, 4);
    let b = square::<f64>(37.2, 41.1);

    println!("{:?}", a);
    println!("{:?}", b);
}