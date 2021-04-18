fn val() -> i32 {
    5
}

fn main() {
    let add = |a: fn() -> i32, (b, c)| (a)() + b + c;
    let r = add(val, (2, 3));

    println!("{:?}", r);
}