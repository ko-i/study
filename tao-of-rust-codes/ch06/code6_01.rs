fn func_name(arg1: u32, arg2: String) -> Vec<u32> {
    // function body
    [].to_vec()
}

fn r#match(needle: &str, haystack: &str) -> bool {
    haystack.contains(needle)
}

fn main() {
    assert!(r#match("foo", "foobar"));
}