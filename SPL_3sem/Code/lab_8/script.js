//TASK 1
let user = {
    name: 'Masha',
    age: 21
};
let user_copy = { ...user };
console.group("User");
console.log(user);
console.log(user_copy);
console.groupEnd();

console.group("Numbers");

let numbers = [1, 2, 3];
console.log(numbers);
let numbers_copy = [...numbers];
console.log(numbers_copy);
console.groupEnd();

let user1 = {

    name: 'Masha',
    age: 23,
    location: {
        city: 'Minsk',
        country: 'Belarus'
    }
};
console.group("user1");
console.log(user1);
let user1_copy = { ...user1, location: { ...user1.location } };
console.log(user1_copy);
console.groupEnd();

let user2 = {
    name: 'Masha',
    age: 28,
    skills: ["HTML", "CSS", "JavaScript", "React"]
};
let user2_copy = { ...user2, skills: { ...user2.skills } };
console.group("user2");
console.log(user2);
console.log(user2_copy);
console.groupEnd();

const array = [
    { id: 1, name: 'Vasya', group: 10 },
    { id: 2, name: 'Ivan', group: 11 },
    { id: 3, name: 'Masha', group: 12 },
    { id: 4, name: 'Petya', group: 10 },
    { id: 5, name: 'Kira', group: 11 },
]
const array_copy = array.map(item => ({ ...item }));
console.group("Array");
console.log(array);
console.log(array_copy);
console.groupEnd();

let user4 = {
    name: 'Masha',
    age: 19,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        exams: {
            maths: true,
            programming: false
        }
    }
};
let user4_copy = { ...user4, studies: { ...user4.studies, exams: { ...user4.studies.exams } } };
console.group("User 4");
console.log(user4);
console.log(user4_copy);
console.groupEnd();

let user5 = {
    name: 'Masha',
    age: 22,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { maths: true, mark: 8 },
            { programming: true, mark: 4 },
        ]
    }
};
let user5_copy = {
    ...user5, studies: {
        ...user5.studies, department: { ...user5.studies.department, group: 12 },
        exams: user5.studies.exams.map(exams => ({ ...exams, mark: 10 }))
    }
};
console.group("user5");
console.log(user5);
console.log(user5_copy);
console.groupEnd();

let user6 = {
    name: 'Masha',
    age: 21,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            {
                maths: true,
                mark: 8,
                professor: {
                    name: 'Ivan Ivanov ',
                    degree: 'PhD'
                }
            },
            {
                programming: true,
                mark: 10,
                professor: {
                    name: 'Petr Petrov',
                    degree: 'PhD'
                }
            },
        ],
    }
};
let user6_copy = {
    ...user6, studies: {
        ...user6.studies, department: { ...user6.studies.department },
        exams: user6.studies.exams.map(exams => ({ ...exams, professor: { ...exams.professor, name: "Dmitry shiman" } }))
    }
};
console.group("user6");
console.log(user6);
console.log(user6_copy);
console.groupEnd();

let user7 = {
    name: 'Masha',
    age: 20,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            {
                maths: true,
                mark: 8,
                professor: {
                    name: 'Ivan Petrov',
                    degree: 'PhD',
                    articles: [
                        { title: "About HTML", pagesNumber: 3 },
                        { title: "About CSS", pagesNumber: 5 },
                        { title: "About JavaScript", pagesNumber: 1 },
                    ]
                }
            },
            {
                programming: true,
                mark: 10,
                professor: {
                    name: 'Petr Ivanov',
                    degree: 'PhD',
                    articles: [
                        { title: "About HTML", pagesNumber: 3 },
                        { title: "About CSS", pagesNumber: 5 },
                        { title: "About JavaScript", pagesNumber: 1 },
                    ]
                }
            },
        ],
    }
};

let user7Copy = {
    ...user7,
    studies: {
      ...user7.studies,
      exams: user7.studies.exams.map(exam => ({
        ...exam,
        professor: {
          ...exam.professor,
          articles: exam.professor.articles.map(article => ({
            ...article,
            pagesNumber: article.title === "About CSS" ? 3 : article.pagesNumber
          }))
        }
      }))
    }
};

console.group("user7");
console.log(user7);
console.log(user7Copy);
console.groupEnd();

let store = {
    state: {
      profilePage: {
        posts: [
          { id: 1, message: 'Hi', likesCount: 12 },
          { id: 2, message: 'By', likesCount: 1 }
        ],
        newPostText: 'About me'
      },
      dialogsPage: {
        dialogs: [
          { id: 1, name: 'Valera' },
          { id: 2, name: 'Andrey' },
          { id: 3, name: 'Sasha' },
          { id: 4, name: 'Viktor' }
        ],
        messages: [
          { id: 1, message: 'hi' },
          { id: 2, message: 'hi hi' },
          { id: 3, message: 'hi hi hi' }
        ]
      },
      sidebar: []
    }
};

let store_copy = {
    ...store,
    state: {
      ...store.state,
      profilePage: {
        ...store.state.profilePage,
        posts: store.state.profilePage.posts.map(post => ({
          ...post,
          message: "Hello"
        }))
      },
      dialogsPage: {
        ...store.state.dialogsPage,
        messages: store.state.dialogsPage.messages.map(message => ({
          ...message,
          message: "Hello"
        }))
      }
    }
}
console.group("Sotre");
console.log(store);
console.log(store_copy);
console.groupEnd();

//TASK 2
