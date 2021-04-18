fn counter() -> fn(i32) -> i32 {
    fn inc(n: i32) -> i32 {
        n + 1
    }

    inc
}

fn main() {
    let f = counter();

    println!("{:?}", f(1));
}