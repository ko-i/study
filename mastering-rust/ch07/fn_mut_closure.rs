fn main() {
    let mut a = String::from("Hey!");
    let mut fn_mut_closure = || {
        a.push_str("Alice");
    };

    fn_mut_closure();
    println!("Main says: {}", a);
}