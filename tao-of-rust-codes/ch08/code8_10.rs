fn main() {
    let s = "Per Martin-Lof";

    let (first, last) = s.split_at(12);
    println!("{:?}", first);
    println!("{:?}", last);
}