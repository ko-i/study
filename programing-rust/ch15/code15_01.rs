fn triangle_1(n: i32) -> i32 {
    let mut sum = 0;

    for i in 1 .. n+1 {
        sum += i;
    }

    sum
}

fn triangle_2(n: i32) -> i32 {
    (1 .. n + 1).fold(1, |sum, item| sum + item)
}

fn main() {
    println!("{:?}", triangle_1(3));
    println!("{:?}", triangle_2(3));
}

