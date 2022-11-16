const some_string = "World my age is <age>. Call me <name>. I like <fruits>"

data = {
    name: "Bob",
    fruits: "oranges",    
    age: "23"
}

const fillTemplate = ({ s, m }) => {
    dummy_s = s
    for (property in m)
    {
        let index_first = dummy_s.indexOf("<" + property);
        let index_last = index_first + property.length + 2;
        dummy_s = dummy_s.replace(dummy_s.substring(index_first, index_last), m[property]);    
    }

    return dummy_s;
}

console.log(fillTemplate({s: some_string, m: data }))
