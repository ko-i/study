fn counter(i: i32) -> Box<dyn Fn(i32) -> i32> {
    Box::new(move |n: i32| n + i)
}

fn main() {
    let f = counter(3);

    println!("{:?}", f(1));
}