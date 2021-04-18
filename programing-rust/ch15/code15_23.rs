fn triangle(n: u64) -> u64 {
    (1..n + 1).sum()
}

fn factorial(n: u64) -> u64 {
    (1..n + 1).product()
}

fn main() {
    println!("{:?}", triangle(10));
    println!("{:?}", factorial(20));
}