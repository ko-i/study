fn main() {
    let text = "Xerxes";

    println!("{:?}", text.chars().position(|c| c == 'e'));
    println!("{:?}", text.chars().position(|c| c == 'z'));

    let bytes = b"Xerxes";

    println!("{:?}", bytes.iter().rposition(|&c| c == b'e'));
    println!("{:?}", bytes.iter().rposition(|&c| c == b'Z'));
}