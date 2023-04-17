/*!CK:2595844478!*//*1447666091,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["Mt3Xe"]); }

__d('ShareDialogStatusTypes', ['getObjectValues'], function a(b, c, d, e, f, g, h) { if (c.__markCompiled) c.__markCompiled(); var i = { COMPOSING: 'composing', ERROR: 'error', POSTING: 'posting', SUCCESS: 'success' }, j = h(i); f.exports = babelHelpers._extends({}, i, { ALL: j, isValid: function (k) { return j.some(function (l) { return l === k; }); } }); }, null);
__d('ShareDialogStaticTitle.react', ['React', 'LeftRight.react', 'XUICloseButton.react', 'XUIDialogTitle.react', 'cx', 'emptyFunction', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n) { if (c.__markCompiled) c.__markCompiled(); var o = h.PropTypes, p = h.createClass({ displayName: 'ShareDialogStaticTitle', propTypes: { onClose: o.func, renderInline: o.bool, title: o.string }, getDefaultProps: function () { return { onClose: m, renderInline: false }; }, render: function () { var q = h.createElement(j, { className: "_51-t", label: n._("Close"), onClick: this.props.onClose }); if (this.props.renderInline) { return (h.createElement(i, null, this.props.title, q)); } else return (h.createElement(k, { showCloseButton: false }, this.props.title, this.props.children, q)); } }); f.exports = p; }, null);
__d('ShareDialogOsricController', ['ActorURI', 'AsyncRequest', 'OnlyMeSharerSaveNux.react', 'Parent', 'React', 'ReactDOM', 'ShareDialog.react', 'ShareDialogAudienceTypes', 'ShareDialogDataSources', 'ShareDialogStatusTypes', 'ShareNowCounter', 'ShareNowCounterEvent', 'SharerType', 'UFIInstanceState', 'XShareDialogSubmitController', 'uniqueID'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) { if (c.__markCompiled) c.__markCompiled(); var x, y, z, aa, ba, ca, da; function ea() { ha({ type: q.POSTING }); } function fa(ja) { r.logEvent(s.SHARE_POST_SUCCESS); ha({ type: q.SUCCESS, message: ja.payload.message, showOnlyMeSharerSaveNux: ja.payload.showOnlyMeSharerSaveNux, shareType: ja.payload.audience }); } function ga(ja) { r.logEvent(s.SHARE_POST_ERROR); ha({ type: q.ERROR, title: ja.errorSummary, message: ja.errorDescription }); } function ha(ja) { if (ja.showOnlyMeSharerSaveNux && ja.shareType && aa && ba && ca) { m.render(l.createElement(j, { caretId: aa, storyContainerId: ba, colectionId: ca, objectId: da, shareType: ja.shareType }), y); } else m.render(l.createElement(n, babelHelpers._extends({}, x, { contextConfig: { actorID: x.userId, composerID: z, gks: x.gks, targetID: x.userId }, shown: true, onPost: function (ka) { ia.onPost(ka, ea, fa, ga); }, status: ja })), y); } var ia = { getPropsFromAsyncResponse: function (ja) { var ka = ja.sources, la = babelHelpers.objectWithoutProperties(ja, ['sources']), ma = ka.person, na = ka.personTag, oa = ka.personWall, pa = ka.group, qa = ka.page, ra = ka.mentions, sa = ka.place, ta = ka.action, ua = ka.object, va = new p().addSource(p.TYPES.ACTION, ta).addSource(p.TYPES.GROUP, pa).addSource(p.TYPES.MENTIONS, ra).addSource(p.TYPES.MESSAGE, ma).addSource(p.TYPES.OBJECT, ua).addSource(p.TYPES.PAGE, qa).addSource(p.TYPES.PERSON, na).addSource(p.TYPES.PERSON_WALL, oa).addSource(p.TYPES.PLACE, sa); return babelHelpers._extends({ dataSources: va }, la); }, onPost: function (ja, ka, la, ma) { r.logEvent(s.SHARE_POST); if (ja.audienceType === o.OWN) { r.logEvent(s.SHARE_POST_OWN); } else if (ja.audienceType === o.PERSON) { r.logEvent(s.SHARE_POST_PERSON); } else if (ja.audienceType === o.PAGE) { r.logEvent(s.SHARE_POST_PAGE); } else if (ja.audienceType === o.GROUP) { r.logEvent(s.SHARE_POST_GROUP); } else if (ja.audienceType === o.MESSAGE) r.logEvent(s.SHARE_POST_MESSAGE); ka && ka(); var na = v.getURIBuilder().setInt('app_id', ja.appId).setInt('owner_id', ja.ownerId).setInt('post_id', ja.postId).setInt('share_type', ja.shareType).setInt('shared_ad_id', ja.sharedAdId).setString('privacy', ja.privacy).setString('message', ja.message).setString('audience_type', ja.audienceType).setIntVector('audience_targets', ja.audienceTargets).setInt('ephemeral_ttl_mode', ja.ephemeralTTLMode).setString('source', ja.source).setIntVector('tagged_people', ja.taggedPeople).setInt('tagged_place', ja.taggedPlace).setInt('tagged_action', ja.taggedActionId).setInt('tagged_object', ja.taggedObjectId).setString('tagged_object_str', ja.taggedObjectStr).setInt('tagged_action_icon', ja.taggedActionIconId).setInt('attribution', ja.attributionId).setStringVector('messaging_tags', ja.messageTags).setStringToStringMap('internalextra', ja.internalExtra || x && x.internalExtra).setInt('internal_preview_image_id', ja.internalPreviewImageID).getURI(); na = h.create(na, ja.actorId); new i().setURI(na).setMethod('POST').setReadOnly(true).setAllowCrossPageTransition(true).setHandler(function () { for (var oa = arguments.length, pa = Array(oa), qa = 0; qa < oa; qa++)pa[qa] = arguments[qa]; la.apply(null, pa); }).setErrorHandler(ma).send(); }, setup: function (ja, ka, la, ma, na, oa) { x = ia.getPropsFromAsyncResponse(ja); y = ka; z = w(); aa = la; ba = ma; ca = na; da = oa; ha({ type: q.COMPOSING }); }, setupInline: function (ja, ka, la) { var ma = k.byClass(ka, 'share_root'), na = this.getPropsFromAsyncResponse(ja), oa = ja.sharerType === t.MESSAGE_ONLY; u.updateState(la, 'inlineShare', { loaded: true, active: true, props: babelHelpers._extends({}, na, { shareLinkNode: ma }), toggling: true, messageOnly: oa }); } }; f.exports = ia; }, null);