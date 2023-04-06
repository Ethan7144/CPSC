class ChatLog {
  Map<String, List<String>> _messagesByUser = {}; // makes a list of messages

  void addMessages(String username, List<String> messages) {
    if (_messagesByUser.containsKey(username)) { // grabs messages by username specifically
      _messagesByUser[username]!.insertAll(0, messages);
    } else {
      _messagesByUser[username] = messages; // will add it to a string with the name of the "Username"
    }
  }

  List<String> getMessagesFrom(String username, {int? offset, int? limit}) {
    List<String> messages = _messagesByUser[username] ?? []; // looks for username
    if (offset != null) {
      messages = messages.skip(offset).toList(); // if no messages are skipped
    }
    if (limit != null) {
      messages = messages.take(limit).toList(); // if there is no limit
    }
    return messages; // return the messages specified with offset or limit.
  }
}
void main() {
  ChatLog chatLog = ChatLog();

  chatLog.addMessages("Ethan", ["Hey there", "What are you up to?"]);
  chatLog.addMessages("Isabel", ["Nothing much, I am just playing Genshin right now"]);
  chatLog.addMessages("Ethan", ["Oh, me too, you want to do some boss runs?"]);
  chatLog.addMessages("Isabel", ["Sure! Lets hit up some of the weeklys real quick! Then I'll go play FGO."]);
  List<String> EthanMessages = chatLog.getMessagesFrom("Ethan", offset: 0, limit: 20); // skips 0 messages, has a limit of 3 messages
  print("Ethan's messages:");
  print(EthanMessages);

  List<String> IsabelMessages = chatLog.getMessagesFrom("Isabel", offset: 0, limit: 2); // has none skipped, has a limit of 1 message
  print("Isabel's messages");
  print(IsabelMessages);
}

