/*!CK:2389776409!*//*1452500116,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["Hznec"]); }

__d('P2PUserEligibilityStore', ['P2PActionConstants', 'EventEmitter', 'MercuryIDs', 'P2PAPI', 'P2PDispatcher', 'P2PGKValues'], function a(b, c, d, e, f, g, h, i, j, k, l, m) { if (c.__markCompiled) c.__markCompiled(); var n, o; 'use strict'; var p, q; n = babelHelpers.inherits(r, i); o = n && n.prototype; function r() { o.constructor.call(this); q = {}; p = l.register(this.onEventDispatched.bind(this)); } r.prototype.onEventDispatched = function (s) { var t = s.data, u = s.type; switch (u) { case h.USER_ELIGIBILITY_UDPATED: this.handleEligibilityUpdated(t); this.emit('change'); break; } }; r.prototype.getEligibilityByUserIDs = function (s) { var t = [], u, v, w = {}; for (var x = 0; x < s.length; x++) { v = s[x]; u = q[v]; if (u === undefined) { q[v] = null; t.push(v); } w[v] = q[v]; } if (m.P2PEnabled && t.length) k.getUserEligibility({ userIDs: t }); return w; }; r.prototype.getEligibilityByUserID = function (s) { var t = this.getEligibilityByUserIDs([s]); return t[s]; }; r.prototype.getEligibilityByThreadID = function (s) { return (this.getEligibilityByUserID(j.getUserIDFromThreadID(s))); }; r.prototype.handleEligibilityUpdated = function (s) { for (var t = 0; t < s.length; t++)q[s[t].user_id] = s[t].p2p_eligible; }; f.exports = new r(); }, null);
__d('P2PSendMoneyButton.react', ['CurrentEnvironment', 'immutable', 'P2PAbstractSendMoneyButton.react', 'P2PActions', 'P2PErrorDialog.react', 'P2PGKValues', 'P2PGroupSendDialog.react', 'P2PLogger', 'P2PPaymentLoggerEvent', 'P2PPaymentLoggerEventFlow', 'P2PPasswordProtectionNUXDialog.react', 'P2PPasswordProtectionStatusTypes', 'P2PSendMoneyDialog.react', 'P2PUserEligibilityContainer.react', 'P2PSendMoneyNUXContextualDialog.react', 'P2PSendMoneySuccessDialog.react', 'P2PTransferParam', 'P2PTransferStore', 'P2PTransferRiskResult', 'P2PUnderManualReviewDialog.react', 'P2PVerificationFlowHelper', 'React', 'ReactDOM', 'ReactLayeredComponentMixin', 'emptyFunction', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, aa, ba, ca, da, ea, fa, ga) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var ha = ca.PropTypes, ia = ca.createClass({ displayName: 'P2PSendMoneyButton', mixins: [ea], propTypes: { amount: ha.string, button: ha.object, groupThreadFBID: ha.string, flyoutAlignment: ha.string, isNewEmptyLocalThread: ha.bool, isGroupChat: ha.bool, onTrigger: ha.func, participants: ha.instanceOf(i.List), platformData: ha.object, sendMoneyDialogShown: ha.bool, threadID: ha.string, threadFBID: ha.string }, getDefaultProps: function () { return { amount: '', groupThreadFBID: '', onTrigger: fa, sendMoneyDialogShown: false }; }, getInitialState: function () { return { sendMoneyNUXDismissed: false }; }, log: function (ja, ka) { o.log(ja, babelHelpers._extends({ www_event_flow: q.UI_FLOW_P2P_SEND }, ka)); }, canShowSendMoneyDialog: function () { return !!(this.props.participants && this.props.participants.size); }, originalCreateTransactionResponse: null, _onButtonClick: function () { var ja = this.getRecipient(); this.log(p.UI_ACTN_SEND_MONEY_BUTTON_CLICKED, { object_id: ja && ja.userID }); this.canShowSendMoneyDialog() && this.showSendMoneyDialog(); }, hideSendMoneyDialog: function () { k.chatSendViewClosed({ threadID: this.props.threadID }); }, showSendMoneyDialog: function () { k.chatSendViewOpened({ referrer: this.props.referrer, threadID: this.props.threadID }); }, _handleDialogToggle: function (ja) { if (!ja) { this.hideSendMoneyDialog(); } else this.showSendMoneyDialog(); }, handlePaymentRequestSuccess: function () { this.hideSendMoneyDialog(); this.props.onTrigger(); }, handleOnSendSuccess: function (ja) { this.hideSendMoneyDialog(); var ka = ja[x.RISK_RESULT]; this.originalCreateTransactionResponse = ja; if (ka === z.REQUIRE_VERIFICATION) { ba.startVerificationFlow(ja.id, true, this.handleVerificationCompleted); } else if (ka === z.UNDER_MANUAL_REVIEW) { this.showUnderManualReviewDialog(); } else this.handlePostSendSteps(false); }, handleVerificationCompleted: function (ja) { this.handlePostSendSteps(!ja); }, handlePostSendSteps: function (ja) { var ka = this.originalCreateTransactionResponse, la = ka.passwordProtection === s.NOT_SET; if (!ja && ka.isFirstSend) { this._passwordNUXPending = la; this.showSendSuccessDialog(); } else if (la) { this.showPasswordProtectionDialog(); } else k.hideDialog(); this.originalCreateTransactionResponse = null; this.props.onTrigger(); }, handleConfirmationOKClick: function () { if (this._passwordNUXPending) { this._passwordNUXPending = false; this.showPasswordProtectionDialog(); } else k.hideDialog(); }, handleSendError: function (ja) { this.showErrorDialog(ja); }, handlePaymentRequestError: function (ja) { this.showPaymentRequestErrorDialog(ja); }, getMoneyButtonNode: function () { return da.findDOMNode(this.refs.p2pSendMoneyButton); }, getRecipient: function () { if (!this.props.isGroupChat && this.props.participants) { return this.props.participants.first(); } else return this.getGroupSendRecipient(); }, getGroupSendRecipient: function () { return (this.props.participants && this.props.participants.find((function (ja) { return ja.userID === this.props.groupSendRecipientUserID; }).bind(this))); }, showErrorDialog: function (ja) { var ka = ga._("Problem Sending Money"); k.showDialog(l, { error: ja, onOKClick: k.hideDialog, title: ka }); }, showPaymentRequestErrorDialog: function (ja) { var ka = ga._("Problem Requesting Money"); k.showDialog(l, { error: ja, onOKClick: k.hideDialog, title: ka }); }, showPasswordProtectionDialog: function () { k.showDialog(r, { onComplete: k.hideDialog }); }, showSendSuccessDialog: function () { k.showDialog(w, { onClose: this.handleConfirmationOKClick }); }, showUnderManualReviewDialog: function () { k.showDialog(aa, { onClose: this.handlePostSendSteps.bind(this, false) }); }, shouldShowNUX: function () { return (!this.state.sendMoneyNUXDismissed && !m.P2PUserAddedCredentialBefore && !y.hasSentDuringSession()); }, renderLayers: function () { var ja = {}, ka = 'USD', la = '$', ma = this.getRecipient(); if (this.canShowSendMoneyDialog() && this.props.sendMoneyDialogShown) if (this.shouldShowNUX()) { ja.nux = ca.createElement(v, { context: this.getMoneyButtonNode(), loggingData: { object_id: ma && ma.userID }, flyoutAlignment: this.props.flyoutAlignment, onNextClick: (function () { return this.setState({ sendMoneyNUXDismissed: true }); }).bind(this), onToggle: this._handleDialogToggle }); } else if (!this.props.groupSendRecipientUserID && this.props.isGroupChat && this.props.threadFBID) { ja.groupSendMoneyDialog = ca.createElement(u, { participants: this.props.participants }, ca.createElement(n, { amount: this.props.amount, context: this.getMoneyButtonNode(), flyoutAlignment: this.props.flyoutAlignment, currency: ka, onToggle: this._handleDialogToggle, participants: this.props.participants, referrer: this.props.referrer, threadID: this.props.threadID, threadFBID: this.props.threadFBID })); } else ja.sendMoneyDialog = ca.createElement(u, { participants: this.props.participants, ref: 'send_money_dialog' }, ca.createElement(t, { amount: this.props.amount, context: this.getMoneyButtonNode(), currency: ka, currencySymbol: la, groupThreadFBID: this.props.groupThreadFBID, flyoutAlignment: this.props.flyoutAlignment, memoText: this.props.memoText, onToggle: this._handleDialogToggle, onError: this.handleSendError, onPaymentRequestError: this.handlePaymentRequestError, onPaymentRequestSuccess: this.handlePaymentRequestSuccess, onSendSuccess: this.handleOnSendSuccess, platformData: this.props.platformData, receiver: ma, ref: 'send_money_dialog', referrer: this.props.referrer, paymentRequestID: this.props.paymentRequestID, useModal: this.props.useModal })); return ja; }, render: function () { var ja = this.getRecipient(); if (this.props.isNewEmptyLocalThread && this.props.participants.size > 1) return null; return (ca.createElement(j, { button: this.props.button, className: this.props.className, isActive: this.canShowSendMoneyDialog() && this.props.sendMoneyDialogShown, isMessenger: !!h.messengerdotcom, onClick: this._onButtonClick, recipientName: ja && ja.short_name, ref: 'p2pSendMoneyButton' })); } }); f.exports = ia; }, null);
__d('P2PSendMoneyContainer.react', ['CurrentUser', 'immutable', 'ImmutableObject', 'MercuryIDs', 'MercuryParticipants', 'MercuryShareAttachmentRenderLocations', 'MercuryThreads', 'P2PSendMoneyButton.react', 'P2PSendMoneyDialogStore', 'React', 'StoreAndPropBasedStateMixin'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var s = q.PropTypes, t = q.createClass({ displayName: 'P2PSendMoneyContainer', propTypes: { button: s.node, className: s.string, flyoutAlignment: s.string, participantIDs: s.array, onTrigger: s.func, threadID: s.string }, getDefaultProps: function () { return { referrer: m.CHAT }; }, mixins: [r(l, n, p)], statics: { calculateState: function (u) { var v = u.threadID, w = null, x = u.participantIDs, y = null, z = null, aa, ba, ca = u.referrer; if (!v) return {}; aa = p.getStateByThreadID(v); ba = aa && aa.referrer; if (ca === m.WEB_INBOX && ba === m.CHAT || ca === m.CHAT && ba === m.WEB_INBOX) aa = {}; if (v) { w = n.getForFBID(h.getID()).getOrFetch(v); if (!x) x = w && w.participants.filter(function (da) { return (h.getID() !== k.getUserIDFromParticipantID(da)); }); if (x) { y = i.List(); y = y.withMutations(function (da) { x && x.forEach(function (ea) { var fa = l.getOrFetch(ea), ga = k.getUserIDFromParticipantID(ea); fa = fa && j.set(fa, { userID: ga }); if (fa) da.push(fa); }); }); } } z = n.get().isNewEmptyLocalThread(v); return babelHelpers._extends({}, aa, { participants: y, isNewEmptyLocalThread: z, isGroupChat: k.isGroupChat(v) && !z, threadID: v, threadFBID: w && w.thread_fbid, referrer: ba || ca }); } }, render: function () { return (q.createElement(o, babelHelpers._extends({}, this.state, { button: this.props.button, className: this.props.className, flyoutAlignment: this.props.flyoutAlignment, onTrigger: this.props.onTrigger }))); } }); f.exports = t; }, null);