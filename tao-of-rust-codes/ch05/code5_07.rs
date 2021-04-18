#[derive(Debug, Copy, Clone)]
struct A {
    a: i32,
    b: u32,
}

fn main() {
    let a = A {a: 1, b: 2};
    let b = a;

    println!("{:?}", a);
    println!("{:?}", b);
}