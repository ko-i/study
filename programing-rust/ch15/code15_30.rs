fn main() {
    let a = ["Pack ", "my ", "box ", "with ", "five ", "dozen ", "liquor ", "jugs"];

    let pangram = a.iter().fold(String::new(), |mut s, &w| {
        s.push_str(w);

        s
    });

    println!("{:?}", pangram);
}