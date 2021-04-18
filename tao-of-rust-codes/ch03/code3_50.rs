fn test_copy<T: Copy>(i: T) {
    println!("hhh");
}

fn main() {
    let a = "String".to_string();
    test_copy(a);
}