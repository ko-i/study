fn sum(a: i32, b: i32) -> i32 {
    a + b
}

fn product(a: i32, b: i32) -> i32 {
    a * b
}

type MathOp = fn(i32, i32) -> i32;

fn math(op: &str, a: i32, b: i32) -> MathOp {
    match op {
        "sum" => sum,
        _ => product,
    }
}

fn main() {
    let (a, b) = (2, 3);

    let sum = math("sum", a, b);
    let product = math("product", a, b);

    println!("{:?}", sum);
    println!("{:?}", product);
}