class Note:
    def __init__(self, memo, tags=[]):
        self.memo = memo
        self.tags = tags

    def print_memo(self):
        print(f"Message: {self.memo}")
        print("\tTags: ", end="")
        for tag in self.tags:
            print(tag, end=" ")
        print()


class Notebook:
    def __init__(self):
        self.notes = []

    def add_note(self):
        message = input("What memo do you want to write? ")
        tags = []
        while True:
            temp = input("Add Tag (or type \"quit\") ")
            if temp == "quit":
                break
            else:
                tags.append(temp)
        new_note = Note(message, tags)
        self.notes.append(new_note)

    def print_notebook(self):
        for note in self.notes:
            note.print_memo()

    def find_notes_by_tag(self, tag):
        # return a list of all notes with the specified tag
        noteByTag = []
        for note in self.notes:
            for tags in note.tags:
                if tag == tags:
                    noteByTag.append(note)
                    break

        return noteByTag

    def print_unique_tags(self):
        # print all the tags used in the notebook
        # make a list with all the tags first then print so we can check for uniqueness
        uniqueTags = []
        unique = True
        for note in self.notes:
            for tag in note.tags:
                unique = True
                for t in uniqueTags:
                    if t == tag:
                        unique = False
                if (unique == True):
                    uniqueTags.append(tag)

        for uni in uniqueTags:
            print(uni, end=" ")
        print()


if __name__ == "__main__":
    notebook1 = Notebook()
    notebook1.add_note()
    notebook1.add_note()
    notebook1.print_notebook()

    # Use these to test your newly-made functions
    memos = notebook1.find_notes_by_tag("school")
    for memo in memos:
        memo.print_memo()
    notebook1.print_unique_tags()
