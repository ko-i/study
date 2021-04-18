fn main() {
    let mut v = vec![100, 32, 57];

    for i in &mut v {
        println!("{}", i);
        *i += 50;
    }

    for i in &mut v {
        println!("{}", i);
    }
}