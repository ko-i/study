fn join(s: &String) -> String {
    // let append = *s;

    "Hello".to_string() + &s
}

fn main() {
    let x = " hello".to_string();

    let y = join(&x);

    println!("{:?}", y);
    println!("{:?}", x);
}