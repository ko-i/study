fn swap((x, y): (&str, i32)) -> (i32, &str) {
    (y, x)
}

fn main() {
    let t = ("Alex", 18);
    let t = swap(t);

    println!("{:?}", t);
}