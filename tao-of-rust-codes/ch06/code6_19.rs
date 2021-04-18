fn counter(i: i32) -> fn(i32) -> i32 {
    fn inc(n: i32) -> i32 {
        n + i
    }

    inc
}

fn main() {
    let f = counter(2);

    println!("{:?}", f(1));
}