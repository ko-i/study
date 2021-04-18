fn main() {
    let s = "Lowe 老虎 Leopard";

    println!("{:?}", s.find('w'));
    println!("{:?}", s.find('老'));
    println!("{:?}", s.find('虎'));
    println!("{:?}", s.find('e'));
    println!("{:?}", s.find("Leopard"));
    println!("{:?}", s.rfind('L'));
    println!("{:?}", s.find(char::is_whitespace));
    println!("{:?}", s.find(char::is_lowercase));
}