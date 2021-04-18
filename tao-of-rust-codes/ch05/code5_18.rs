fn foo(s: String) -> String {
    let w = " world".to_string();
    s + &w
}

fn main() {
    let s = "hello".to_string();
    let ss = foo(s);

    // println!("{:?}", s);
    println!("{:?}", ss);
}