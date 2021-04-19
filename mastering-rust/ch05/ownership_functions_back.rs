fn take_the_n(n: u8) {}
fn take_the_s(s: String) -> String {
    println!("Inside function {}", s);
    s
}

fn main() {
    let n = 5;
    let s = String::from("string");

    take_the_n(n);
    let s = take_the_s(s);

    println!("n: {}", n);
    println!("s: {}", s);
}