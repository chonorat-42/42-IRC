//
// Created by pgouasmi on 4/12/24.
//

#ifndef NUMERICREPLIES_HPP
#define NUMERICREPLIES_HPP

#include <string>
#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include "StringUtils.hpp"

enum COLORS
{
	WHITE,
	BLACK,
	BLUE,
	GREEN,
	RED,
	BROWN,
	MAGENTA,
	ORANGE,
	YELLOW,
	LIME,
	TEAL,
	CYAN,
	LBLUE,
	PINK,
	GREY,
	LGREY
};

#define DEFAULT ""
#define BOLDR "\x02"
#define ITALIC "\x1D"
#define UNDERLINE "\x1F"
#define STRIKETHROUGH "\x1E"

void	sendServerReply(int const client_fd, std::string client_buffer, int color, std::string mode);

# define user_id(nickname, username) (":" + nickname + "!" + username + "@124.0.0.1")

# define RPL_WELCOME(user_id, nickname) (":localhost 001 " + nickname + " :Welcome to the Internet Relay Network " + user_id + "\r\n")
# define RPL_YOURHOST(client, servername, version) (":localhost 002 " + client + " :Your host is " + servername + " (localhost), running version " + version + "\r\n")
# define RPL_CREATED(client, datetime) (":localhost 003 " + client + " :This server was created " + datetime + "\r\n")
# define RPL_MYINFO(client, servername, version, user_modes, chan_modes, chan_param_modes) (":localhost 004 " + client + " " + servername + " " + version + " " + user_modes + " " + chan_modes + " " + chan_param_modes + "\r\n")
# define RPL_ISUPPORT(client, tokens) (":localhost 005 " + client + " " + tokens " :are supported by this server\r\n")

# define ERR_REQUESTTIMEOUT(client, server) (":localhost 408 " + client + " " + server + " :Request Timeout.\r\n")
# define ERR_UNKNOWNCOMMAND(client, command) (":localhost 421 " + client + " " + command + " :Unknown command\r\n")

// INVITE
# define ERR_NEEDMOREPARAMS(client, command) (":localhost 461 " + client + " " + command + " :Not enough parameters.\r\n")
# define ERR_NOSUCHCHANNEL(client, channel) (":localhost 403 " + client + " #" + channel + " :No such channel\r\n")
# define ERR_NOTONCHANNEL(client, channel) (":localhost 442 " + client + " #" + channel + " :The user is not on this channel.\r\n")
# define ERR_USERONCHANNEL(client, nick, channel) (":localhost 443 " + client + " " + nick + " #" + channel + " :Is already on channel\r\n")
# define RPL_INVITING(user_id, client, nick, channel) (user_id + " 341 " + client + " " + nick + " #" + channel + "\r\n")
# define RPL_INVITE(user_id, invited, channel) (user_id + " INVITE " + invited + " #" + channel + "\r\n")

//BAN
#define ERR_YOUREBANNED(client, reason) (":localhost 465 " + client + " :" + reason + "\r\n")

// JOIN
# define RPL_JOIN(user_id, channel) (user_id + " JOIN :#" +  channel + "\r\n")
# define ERR_BANNEDFROMCHAN(client, channel) (":localhost 474 " + client + " #" + channel + " :Cannot join channel (+b)\r\n")
# define ERR_BADCHANNELKEY(client, channel) (":localhost 475 " + client + " #" + channel + " :Cannot join channel (+k)\r\n")
# define ERR_INVITEONLYCHAN(nickname, channel) (":localhost 473 " + nickname + " #" + channel + " :Cannot join channel (+i)\r\n")

// KICK
# define ERR_USERNOTINCHANNEL(client, nickname, channel) (":localhost 441 " + client + " #" + channel + " " + nickname + " :is not on that channel\r\n")
# define RPL_KICK(user_id, channel, kicked, reason) (user_id + " KICK #" + channel + " " + kicked + " " + reason + "\r\n")

// KILL
# define ERR_NOPRIVILEGES(client) (":localhost 481 " + client + " :Permission Denied - You're not an IRC operator\r\n")
# define RPL_KILL(user_id, killed, comment) (user_id + " KILL " + killed + " " + comment + "\r\n")

// MODE
/* user mode */
#define MODE_USERMSG(client, mode) (":" + client + " MODE " + client + " :" + mode + "\r\n")
#define ERR_UMODEUNKNOWNFLAG(client) (":localhost 501 " + client + " :Unknown MODE flag\r\n")
#define ERR_USERSDONTMATCH(client) ("502 " + client + " :Cant change mode for other users\r\n")
#define RPL_UMODEIS(client, mode) (":localhost 221 " + client + " " + mode + "\r\n")
/* channel mode */
#define MODE_CHANNELMSG(channel, mode) (":localhost MODE #" + channel + " " + mode + "\r\n")
#define MODE_CHANNELMSGWITHPARAM(channel, mode, param) (":localhost MODE #" + channel + " " + mode + " " + param + "\r\n")
#define RPL_CHANNELMODEIS(client, channel, mode) (":localhost 324 " + client + " #" + channel + " " + mode + "\r\n")

//#define RPL_ADDMODE(client, modifier, channel, mode) (":localhost " + client + " #" + channel + " " + modifier + " set mode " + mode + "\r\n")

#define RPL_CHANNELMODEISWITHKEY(client, channel, mode, password) (":localhost 324 " + client + " #" + channel + " " + mode + " " + password + "\r\n")
#define ERR_CANNOTSENDTOCHAN(client, channel) (":localhost 404 " + client + " #" + channel + " :Cannot send to channel\r\n")
#define ERR_CHANNELISFULL(client, channel) (":localhost 471 " + client + " #" + channel + " :Cannot join channel (+l)\r\n")
#define ERR_CHANOPRIVSNEEDED(client, channel) (":localhost 482 " + client + " #" + channel + " :You're not channel operator\r\n")
#define ERR_INVALIDMODEPARAM(client, channel, mode, password) (":localhost 696 " + client + " #" + channel + " " + mode + " " + password + " : password must only contained alphabetic character\r\n")
#define ERR_INVALIDMODEGENERAL(client, channel, mode, reason) (":localhost 696 " + client + " #" + channel + " " + mode + " : " + reason + "\r\n")
#define RPL_ADDMODE(nickname, modifier, mode, channel) (":localhost 324 " + nickname + " #" + channel + " :" + modifier + " set mode " + mode + " on #" + channel + "\r\n")
#define ERR_ADDMODE(nickname, channel, mode, reason) (":localhost 461 " + nickname + " #" + channel + " :" "MODE " + mode + " error: " + reason + "\r\n")
#define RPL_ADDMODEUSER(nickname, target, mode, channel) (":localhost 324 " + nickname + " #" + channel + " :" + target + " " + mode + "\r\n")
#define RPL_ADDVOICE(nickname, username, channel, mode, param) (":" + nickname + "!" + username + "@localhost MODE #" + channel + " " + mode + " " + param + "\r\n")

// MOTD
#define ERR_NOSUCHSERVER(client, servername) (":localhost 402 " + client + " " + servername + " :No such server\r\n")
#define ERR_NOMOTD(client) (":localhost 422 " + client + " :MOTD File is missing\r\n")
#define RPL_MOTDSTART(client, servername) (":localhost 375 " + client + " :- " + servername + " Message of the day - \r\n")
#define RPL_MOTD(client, motd_line) (":localhost 372 " + client + " :" + motd_line + "\r\n")
#define RPL_ENDOFMOTD(client) (":localhost 376 " + client + " :End of /MOTD command.\r\n")


// NAMES
# define RPL_NAMREPLY(client, symbol, channel, list_of_nicks) (":localhost 353 " + client + " " + symbol + " #" + channel + " :" + list_of_nicks + "\r\n")
# define RPL_ENDOFNAMES(client, channel) (":localhost 366 " + client + " #" + channel + " :End of /NAMES list.\r\n")

// NICK
# define ERR_NONICKNAMEGIVEN(client) (":localhost 431 " + client + " :There is no nickname.\r\n")
# define ERR_ERRONEUSNICKNAME(client, nickname) (":localhost 432 " + client + " " + nickname + " :Erroneus nickname\r\n")
# define ERR_NICKNAMEINUSE(client, nickname) (":localhost 433 " + client + " " + nickname + " :Nickname is already in use.\r\n")
# define RPL_NICK(oclient, uclient, client) (":" + oclient + "!" + uclient + "@localhost NICK " +  client + "\r\n")

// NOTICE
# define RPL_NOTICE(nick, username, target, message) (":" + nick + "!" + username + "@localhost NOTICE " + target + " " + message + "\r\n")

// OPER
# define ERR_NOOPERHOST(client) ("491 " + client + " :No O-lines for your host\r\n")
# define RPL_YOUREOPER(client, channel) (":localhost 381 " + client + " #" + channel + " :You are now operator on channel #" + channel + "\r\n")

// PART
# define RPL_PART(user_id, channel, reason) (user_id + " PART #" + channel + " " + (reason.empty() ? "." : reason ) + "\r\n")

// PASS
# define ERR_PASSWDMISMATCH(client) (":localhost 464 " + client + " :Password incorrect.\r\n")

// PING
# define RPL_PONG(user_id, token) (user_id + " PONG : " + token + "\r\n")

// QUIT
# define RPL_QUIT(user_id, reason) (user_id + " QUIT : " + reason + "\r\n")
# define RPL_ERROR(user_id, reason) (user_id + " ERROR :" + reason + "\r\n")

// PRIVMSG
# define ERR_NOSUCHNICK(client, target) (":localhost 401 " + client + " " + target + " :No such nick/channel\r\n")
# define ERR_NORECIPIENT(client) ("411 " + client + " :No recipient given PRIVMSG\r\n")
# define ERR_NOTEXTTOSEND(client) ("412 " + client + " :No text to send\r\n")
# define RPL_PRIVMSG(nick, username, target, message) (":" + nick + "!" + username + "@localhost PRIVMSG " + target + " " + message + "\r\n")

// TOPIC
# define RPL_TOPIC(client, channel, topic) (":localhost 332 " + client + " #" + channel + " :" + topic + "\r\n")
# define RPL_NOTOPIC(client, channel) (":localhost 331 " + client + " #" + channel + " :No topic is set\r\n")

// USER
# define ERR_ALREADYREGISTERED(client) (":localhost 462 " + client + " :You may not reregister.\r\n")

// LIST
# define RPL_LIST(client, channel, visible, topic) (":localhost 322 " + client + " " + channel + " " + StringUtils::ltos(visible) + " :" + topic + "\r\n")
# define RPL_LISTEND(client) (":localhost 323 " + client + " :End of /LIST\r\n")

//WHO
# define RPL_WHOREPLY(channel, callerUsername, onChannelUsername) (":localhost 352 " + callerUsername + " #" + channel + " " + onChannelUsername)
# define RPL_ENDOFWHO(client) (":localhost 315 " + client + " :End of WHO list.\r\n")

//WHOIS
# define RPL_WHOISUSER(nickname, username, hostname, realname) (":localhost 311 " + nickname + " " + username + " " + hostname + " * :" + realname + "\r\n")
# define RPL_WHOISCHANNELS(nickname, channels) (":localhost 319 " + nickname + " :" + channels + "\r\n")
# define RPL_WHOISSERVER(nickname, servername) (":localhost 312 " + nickname + " " + servername + " :Server's info\r\n")
# define RPL_WHOISOPERATOR(nickname) (":localhost 313 " + nickname + " :is an IRC operator\r\n")
# define RPL_ENDOFWHOIS(nickname) (":localhost 318 " + nickname + " :End of WHOIS list\r\n")

//ARGERROR
#define ERR_ARG(callerNickname, command, usage) (":localhost 461" + callerNickname + " " + command + ":Usage: " + usage + "\r\n")

#endif

