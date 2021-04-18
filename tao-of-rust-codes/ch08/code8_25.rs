fn main() {
    let s = "Hello\tworld\t";
    println!("{:?}", s.replace("\t", " "));
    println!("{:?}", s.replace("\t", " ").trim());

    let s = "this is old old 123";
    println!("{:?}", s.replace("old", "new"));
    println!("{:?}", s.replacen("old", "new", 1));
    println!("{:?}", s.replacen("o", "a", 3));

    println!("{:?}", s.replacen(char::is_numeric, "new", 1));
}