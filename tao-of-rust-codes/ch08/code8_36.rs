fn main() {
    println!("{:?}", format!("{:+}", 1234));
    println!("{:?}", format!("{:+x}", 1234));
    println!("{:?}", format!("{:+#x}", 1234));
    println!("{:?}", format!("{:b}", 1234));
    println!("{:?}", format!("{:#b}", 1234));
    println!("{:?}", format!("{:#20b}", 1234));
    println!("{:?}", format!("{:<#20b}", 1234));
    println!("{:?}", format!("{:^#20b}", 1234));
    println!("{:?}", format!("{:>+#15x}", 1234));
    println!("{:?}", format!("{:>+#015x}", 1234));
}