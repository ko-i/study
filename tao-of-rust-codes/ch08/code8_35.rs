fn main() {
    let s: String = format!("{}Rust", "Hello");
    println!("{:?}", s);

    println!("{:?}", format!("{:5}", "HelloRust"));
    println!("{:?}", format!("{:5.3}", "HelloRust"));
    println!("{:?}", format!("{:10}", "HelloRust"));
    println!("{:?}", format!("{:<12}", "HelloRust"));
    println!("{:?}", format!("{:>12}", "HelloRust"));
    println!("{:?}", format!("{:^12}", "HelloRust"));
    println!("{:?}", format!("{:^12.5}", "HelloRust"));
    println!("{:?}", format!("{:=^12.5}", "HelloRust"));
    println!("{:?}", format!("{:*^12.5}", "HelloRust"));

    println!("{:?}", format!("{:5}", "th\u{e9}"));
}