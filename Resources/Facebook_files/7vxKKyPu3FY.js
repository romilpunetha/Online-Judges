/*!CK:2302384424!*//*1453177156,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["xhtpw"]); }

__d("VideoEditEvent", [], function a(b, c, d, e, f, g) { c.__markCompiled && c.__markCompiled(); f.exports = { JS_LOADED: "js_loaded", PAGE_LOAD_STARTED: "page_loaded_started", EDIT_VIDEO_ASSET: "edit_video_asset", PAGE_LOADED: "page_loaded", SAVE_ERROR: "save_error", SAVE_START: "save_start", PREFERRED_THUMBNAIL_CHANGE: "preferred_thumbnail_change", THUMBNAIL_CREATE_STARTED: "thumbnail_create_started", THUMBNAIL_CREATED: "thumbnail_created", SAVE_SUCCESS: "save_success", CTA_UNEXPECTED: "cta_unexpected", CTA_CHANGE_REQUEST: "cta_change_request", VIDEO_DELETE: "video_delete", CAPTIONS_UPLOADED: "captions_uploaded", CAPTIONS_REMOVED: "captions_removed", CAPTIONS_UPDATED_DEFAULT_LOCALE: "captions_updated_default_locale", NO_EDIT_PERMISSION: "no_edit_permission", CANCEL: "cancel_flow", SAVE_CLICKED: "save_clicked", REQUEST_NEW_STORY: "new_story_requested", RECEIVED_NEW_STORY: "new_story_received", REPLACED_OLD_STORY: "old_story_replaced", ERROR_NO_NEW_STORY: "error_no_new_story" }; }, null);
__d("VideoEditFlow", [], function a(b, c, d, e, f, g) { c.__markCompiled && c.__markCompiled(); f.exports = { DIALOG: "dialog", FORM: "form" }; }, null);
__d('AdsTypeahead.react', ['AdsHelpLink.react', 'AdsValidationIcon.react', 'AdsValidationIconType', 'BackgroundImage.react', 'React', 'ReactChildren', 'SearchableEntry', 'XUICloseButton.react', 'XUITypeahead.react', 'cx', 'joinClasses'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var s = l.PropTypes, t = l.createClass({ displayName: 'AdsTypeahead', propTypes: { autoHighlight: s.bool, disabled: s.bool, disableTooltip: s.bool, errors: s.array, focusedOnInit: s.bool, onQueryStringChange: s.func, onSelectAttempt: s.func, placeholder: s.string, presenter: s.object, searchSource: s.object.isRequired, selectedEntry: s.instanceOf(n) }, getDefaultProps: function () { return { autoHighlight: true, disableTooltip: false }; }, getInitialState: function () { var u = this.props.selectedEntry; return { queryString: this.props.selectedEntry ? u.getTitle() : '', focused: !!this.props.focusedOnInit }; }, componentWillReceiveProps: function (u) { if ('selectedEntry' in u) this.setState({ queryString: u.selectedEntry ? u.selectedEntry.getTitle() : this.state.queryString }); }, focusInput: function () { this.setState({ focused: true }); this.refs.typeahead.focusInput(); }, render: function () { var u = null, v = null; if (this.props.selectedEntry) { u = this.props.selectedEntry; v = this.props.selectedEntry.getPhoto(); } var w = Array.isArray(this.props.errors) && this.props.errors.length ? l.createElement('span', { className: "_1fys" }, l.createElement(i, { messages: this.props.errors, type: j.ERROR_WHITE })) : null, x = r("_1fyt" + (' ' + "_1fyu") + (this.state.focused ? ' ' + "_1fyv" : '') + (!!w ? ' ' + "_1fyw" : ''), this.props.className), y = this.props.placeholder || '', z = !this.props.selectedEntry || !this.state.queryString, aa = !!this.state.queryString && !this.props.selectedEntry, ba = null; if (this.props.tooltipHelpText) ba = l.createElement('span', { className: "_1fyx" }, l.createElement(h, null, this._getTooltipHelpText())); return (l.createElement('div', { className: x, role: 'presentation', title: this.props.disableTooltip ? null : y }, l.createElement('div', { className: "_1fyy" + (!!w ? ' ' + "_1fyz" : '') }, w, l.createElement('div', { className: (this.props.disabled ? "_1fy-" : '') + (' ' + "_1fy_") + (!!u ? ' ' + "_1fz0" : '') + (!!ba ? ' ' + "_1fz1" : '') + (!!v ? ' ' + "_1fz2" : '') }, v && this._renderPhoto(v), u && this._renderClearEntry(), !u && ba, l.createElement(p, { autoHighlight: this.props.autoHighlight, disabled: this.props.disabled, focusedOnInit: this.props.focusedOnInit, placeholder: y, presenter: this.props.presenter, queryString: this.state.queryString, ref: 'typeahead', searchSource: this.props.searchSource, selectOnBlur: aa, showEntriesOnFocus: z, viewStyle: 'rich', onBlur: this._onBlur, onChange: this._onChange, onFocus: this._onFocus, onSelectAttempt: this._onSelectAttempt }))), l.createElement('div', null, this.props.children))); }, _renderPhoto: function (u) { return (l.createElement(k, { backgroundSize: 'cover', className: "_1fz3", height: 24, src: u, width: 24 })); }, _renderClearEntry: function () { if (this.props.disabled) return null; return (l.createElement('div', { className: "_1fz4" }, l.createElement(o, { onClick: this._onClearEntry }))); }, _getTooltipHelpText: function () { return m.map(this.props.tooltipHelpText, function (u, v) { return (l.createElement('p', { className: "_1fz5", key: v }, u)); }); }, _onChange: function (event) { this.setState({ queryString: event.target.value }, this._didChange); }, _didChange: function () { this.props.selectedEntry && this.props.onSelectAttempt && this.props.onSelectAttempt(null); if (this.props.onQueryStringChange) this.props.onQueryStringChange(this.state.queryString); }, _onSelectAttempt: function (u) { this.props.onSelectAttempt && this.props.onSelectAttempt(u); }, _onClearEntry: function () { this.setState({ queryString: '' }, this._onClear); }, _onClear: function () { this.refs.typeahead.focusInput(); this.props.onSelectAttempt && this.props.onSelectAttempt(null); }, _onFocus: function () { this.setState({ focused: true }); }, _onBlur: function () { this.setState({ focused: false }); } }); f.exports = t; }, null);
__d('AdsPEVideoThumbnailPicker.react', ['Image.react', 'LeftRight.react', 'React', 'ReactChildren', 'Image.react', 'XUIButton.react', 'XUIPagerButtons.react', 'XUIText.react', 'clamp', 'cx', 'fbt', 'ix', 'onlyChild'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var u = j.PropTypes, v = j.createClass({ displayName: 'AdsPEVideoThumbnailPicker', propTypes: { thumbnails: u.arrayOf(u.shape({ id: u.string, uri: u.string.isRequired })).isRequired, onChange: u.func.isRequired, index: u.number.isRequired, title: u.string }, _prevImage: function () { this._setImageIndex(this.props.index - 1); }, _nextImage: function () { this._setImageIndex(this.props.index + 1); }, _setImageIndex: function (w) { w = p(w, 0, this.props.thumbnails.length - 1); if (w !== this.props.index) this.props.onChange(w, this.props.thumbnails[w]); }, render: function () { if (this.props.thumbnails.length === 0) return null; var w = this.props.index, x = this.props.thumbnails[w].uri, y = null; if (k.count(this.props.children) > 0) y = j.createElement('div', { className: "_w3" }, t(this.props.children)); return (j.createElement(i, { className: this.props.className, direction: i.DIRECTION.left }, j.createElement(h, { alt: this.props.title, className: "_w9", src: x }), j.createElement('div', { className: "_wf" }, j.createElement('div', { className: "_3-95" }, j.createElement(n, null, j.createElement(m, { image: j.createElement(l, { src: s('/images/ui/x/pager/left.png') }), type: 'button', onClick: this._prevImage }), j.createElement(m, { image: j.createElement(l, { src: s('/images/ui/x/pager/right.png') }), type: 'button', onClick: this._nextImage })), j.createElement(o, { className: "_3-9a", weight: 'bold' }, r._("Thumbnail {selected thumbnail index} of {total number of thumbnails}", [r.param('selected thumbnail index', w + 1), r.param('total number of thumbnails', this.props.thumbnails.length)]))), y))); } }); f.exports = v; }, null);
__d('VideoEditTypedLogger', ['Banzai', 'GeneratedLoggerUtils', 'nullthrows'], function a(b, c, d, e, f, g, h, i, j) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); function k() { this.clear(); } k.prototype.log = function () { i.log('logger:VideoEditLoggerConfig', this.$VideoEditTypedLogger1, h.BASIC); }; k.prototype.logVital = function () { i.log('logger:VideoEditLoggerConfig', this.$VideoEditTypedLogger1, h.VITAL); }; k.prototype.clear = function () { this.$VideoEditTypedLogger1 = {}; return this; }; k.prototype.updateData = function (m) { this.$VideoEditTypedLogger1 = babelHelpers._extends({}, this.$VideoEditTypedLogger1, m); return this; }; k.prototype.setCaptionsCount = function (m) { this.$VideoEditTypedLogger1.captions_count = m; return this; }; k.prototype.setChangedTitle = function (m) { this.$VideoEditTypedLogger1.changed_title = m; return this; }; k.prototype.setEmbeddable = function (m) { this.$VideoEditTypedLogger1.embeddable = m; return this; }; k.prototype.setEvent = function (m) { this.$VideoEditTypedLogger1.event = m; return this; }; k.prototype.setExpirationTime = function (m) { this.$VideoEditTypedLogger1.expiration_time = m; return this; }; k.prototype.setExpirationType = function (m) { this.$VideoEditTypedLogger1.expiration_type = m; return this; }; k.prototype.setExpiredNow = function (m) { this.$VideoEditTypedLogger1.expired_now = m; return this; }; k.prototype.setFlow = function (m) { this.$VideoEditTypedLogger1.flow = m; return this; }; k.prototype.setHasContentCategoryChanged = function (m) { this.$VideoEditTypedLogger1.has_content_category_changed = m; return this; }; k.prototype.setHasContentTagsChanged = function (m) { this.$VideoEditTypedLogger1.has_content_tags_changed = m; return this; }; k.prototype.setPublishNow = function (m) { this.$VideoEditTypedLogger1.publish_now = m; return this; }; k.prototype.setSource = function (m) { this.$VideoEditTypedLogger1.source = m; return this; }; k.prototype.setVC = function (m) { this.$VideoEditTypedLogger1.vc = m; return this; }; k.prototype.setVideoID = function (m) { this.$VideoEditTypedLogger1.video_id = m; return this; }; k.prototype.updateExtraData = function (m) { m = j(i.serializeMap(m)); i.checkExtraDataFieldNames(m, l); this.$VideoEditTypedLogger1 = babelHelpers._extends({}, this.$VideoEditTypedLogger1, m); return this; }; k.prototype.addToExtraData = function (m, n) { var o = {}; o[m] = n; return this.updateExtraData(o); }; var l = { captions_count: true, changed_title: true, embeddable: true, event: true, expiration_time: true, expiration_type: true, expired_now: true, flow: true, has_content_category_changed: true, has_content_tags_changed: true, publish_now: true, source: true, vc: true, video_id: true }; f.exports = k; }, null);
__d('VideoContentCategorySelector.react', ['React', 'VideoContentCategoryType', 'XUISelector.react'], function a(b, c, d, e, f, g, h, i, j) { if (c.__markCompiled) c.__markCompiled(); var k = j.Option, l = h.PropTypes, m = h.createClass({ displayName: 'VideoContentCategorySelector', propTypes: { onChange: l.func, value: l.number }, render: function () { var n = Object.keys(i), o = n.map(function (p) { var q = i[p]; return (h.createElement(k, { key: q.value, value: q.value }, q.label)); }); return (h.createElement(j, { onChange: this.props.onChange, value: this.props.value, defaultValue: i.OTHER.value }, o)); } }); f.exports = m; }, null);
__d('MentionsInputUtility', ['DraftEntity', 'createEditorStateWithEntities'], function a(b, c, d, e, f, g, h, i) { if (c.__markCompiled) c.__markCompiled(); var j = new RegExp(/@\[(\d+):((\\\]|[^\]])+)\]/g), k = new RegExp(/@\[(\d+):(\d+):((\\\]|[^\]])+)\]/g), l = function (n) { var o = n.replace(k, '@[$1:$3]'), p = [], q; while (q = j.exec(o)) { var r = q[2].replace(/\\:/g, ':').replace(/\\]/g, ']').replace(/\n/g, ''), s = { uid: q[1], text: r, offset: q.index, length: r.length, weakreference: false, entity: { uid: q[1], weakreference: false } }; p.push(s); o = o.substr(0, s.offset) + s.text + o.substr(s.offset + q[0].length); j.lastIndex = s.offset + s.length; } return { text: o, ranges: p }; }, m = function (n, o) { var p = this.parseTextWithMentions(n), q = p.text, r = p.ranges; return i({ text: q, ranges: r, decorator: o, entityCreationFn: function (s) { return h.create('MENTION', 'IMMUTABLE', { id: s.uid, isWeak: s.weakreference }); }, splitIntoBlocks: true, allowUndo: true }); }; f.exports = { createFromTextWithMentions: m, parseTextWithMentions: l }; }, null);
__d('ProgressiveDateAndTimePicker.react', ['InlineBlock.react', 'React', 'XUIProgressiveDatepicker.react', 'XUISelector.react', 'cx', 'fbt', 'formatDate'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n) { if (c.__markCompiled) c.__markCompiled(); var o = k.Option, p = i.PropTypes, q = i.createClass({ displayName: 'ProgressiveDateAndTimePicker', propTypes: babelHelpers._extends({}, j.propTypes, { initialHour: p.number, initialMinute: p.number }), getDefaultProps: function () { return { initialHour: -1, initialMinute: -1, maxTime: Date.now() / 1000, minTime: new Date(1906, 0, 0, 0, 0).getTime() / 1000 }; }, getInitialState: function () { return { datePickerResult: { year: this.props.initialYear, month: this.props.initialMonth, day: this.props.initialDay }, hour: this.props.initialHour, minute: this.props.initialMinute }; }, onDateChange: function (r) { this.setState({ datePickerResult: r }, this.onDateAndTimeChange); }, onDateAndTimeChange: function () { if (!this.props.onDateAndTimeChange) return; var r = this.state.datePickerResult, s = babelHelpers._extends({}, r, { hour: this.state.hour, minute: this.state.minute }); this.props.onDateAndTimeChange(s); }, onHourChange: function (event) { this.onSelectorChange(event, 'hour'); }, onMinuteChange: function (event) { this.onSelectorChange(event, 'minute'); }, onSelectorChange: function (event, r) { var s = event.target ? event.target.value : event.value, t = {}; t[r] = s; this.setState(t, this.onDateAndTimeChange); }, render: function () { var r, s; if (this.state.datePickerResult.day) { var t = [i.createElement(o, { key: -1, value: -1 }, m._("Hour:"))]; for (var u = 0; u < 24; u++) { var v = new Date(); v.setHours(u); var w = n(v, 'g A'); t.push(i.createElement(o, { key: u, value: u }, w)); } r = i.createElement(k, { className: "_5vu1", disabled: !this.state.datePickerResult.day, maxheight: this.props.menuMaxHeight, name: this.props.inputPrefix + '_hour', onChange: this.onHourChange, value: this.state.hour }, t); } if (this.state.hour != -1) { var x = [i.createElement(o, { key: -1, value: -1 }, m._("Minute:"))]; for (u = 0; u < 60; u += 10) { var y = '00'; if (u > 0) y = u; x.push(i.createElement(o, { key: u, value: u }, y)); } s = i.createElement(k, { className: "_5vu1", disabled: this.state.hour == -1, maxheight: this.props.menuMaxHeight, name: this.props.inputPrefix + '_minute', onChange: this.onMinuteChange, value: this.state.minute }, x); } return (i.createElement(h, { className: this.props.className }, i.createElement(j, babelHelpers._extends({}, this.props, { onDateChange: this.onDateChange })), r, s)); } }); f.exports = q; }, null);
__d('VideoEditCallToActionFields.react', ['AdsTextInput.react', 'HelpLink.react', 'React', 'cx', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k, l) { if (c.__markCompiled) c.__markCompiled(); var m = j.PropTypes, n = j.createClass({ displayName: 'VideoEditCallToActionFields', propTypes: { ctaLink: m.string, ctaCaption: m.string, onCtaLinkFieldChange: m.func, onCtaCaptionFieldChange: m.func }, render: function () { var o = [j.createElement(h, { label: l._("URL (Required)"), placeholder: l._("Enter the Page or URL you want people to visit"), className: "_3-8x", onChange: this.props.onCtaLinkFieldChange, value: this.props.ctaLink }), j.createElement(h, { label: j.createElement('div', null, l._("Link Description"), j.createElement(i, { tooltip: l._("If you're using a long website address, your display link will show a shorter, friendlier URL.") })), placeholder: l._("Enter a description of the Page or URL"), multiline: false, className: "_3-8x", onChange: this.props.onCtaCaptionFieldChange, value: this.props.ctaCaption }), j.createElement('input', { type: 'hidden', name: 'cta_link', value: this.props.ctaLink }), j.createElement('input', { type: 'hidden', name: 'cta_caption', value: this.props.ctaCaption })]; return (j.createElement('div', null, o)); } }); f.exports = n; }, null);
__d('VideoMultiCaptionDefaultSelector.react', ['HelpLink.react', 'React', 'Selector.react', 'cx', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k, l) { if (c.__markCompiled) c.__markCompiled(); var m = j.Option, n = i.PropTypes, o = 'video_multi_captions_default_selector_'; function p(r) { return o + r; } var q = i.createClass({ displayName: 'VideoMultiCaptionDefaultSelector', propTypes: { defaultLocale: n.string, locales: n.array.isRequired, localesMap: n.object.isRequired }, render: function () { var r = this.props.defaultLocale ? this.props.defaultLocale : 'none', s = i.createElement(m, { value: 'none' }, l._("None")), t = this.props.locales.map(function (v) { return (i.createElement(m, { value: v, key: p(v) }, this.props.localesMap[v], ': ', v)); }, this), u = l._("The language will only appear on videos that don't have your preferred caption language available."); return (i.createElement('div', { className: "_3-8n _3eab" }, l._("Backup Language"), i.createElement(h, { tooltip: u, alignv: 'bottom' }), i.createElement('div', null, i.createElement(j, { name: 'default_captions_locale', defaultValue: r }, s, t)))); } }); f.exports = q; }, null);
__d('VideoRemovableUploadedCaption.react', ['CloseButton.react', 'React', 'cx', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = i.PropTypes; function m(o) { return 'remove_caption[' + o + ']'; } var n = i.createClass({ displayName: 'VideoRemovableUploadedCaption', propTypes: { deletekey: l.number.isRequired, locale: l.string.isRequired, localeName: l.string.isRequired }, getInitialState: function () { return { removed: false }; }, render: function () { return (i.createElement('div', { className: "_2phz _4dez" }, this.renderRemovableCaption())); }, renderRemovableCaption: function () { var o = this.props.locale, p = this.props.localeName; if (this.state.removed) return (i.createElement('div', null, k._("Delete {locale}.", [k.param('locale', o)]), ' ', i.createElement('a', { href: '#', onClick: this._handleUndoRemove }, k._("Undo")), i.createElement('input', { name: m(this.props.deletekey), type: 'hidden', value: o }))); return (i.createElement('div', null, i.createElement('span', { className: "_4de-" }, p, ': ', o), i.createElement(h, { 'aria-labelledby': 'metadata_caption_remove', className: "_3-99 _4de-", onClick: this._handleRemove, size: 'small' }))); }, _handleRemove: function () { this.setState({ removed: true }); }, _handleUndoRemove: function () { this.setState({ removed: false }); } }); f.exports = n; }, null);
__d('VideoMultiCaptionList.react', ['React', 'VideoRemovableUploadedCaption.react', 'cx', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = h.PropTypes, m = 'video_multi_captions_locale_field_'; function n(p) { return m + p; } var o = h.createClass({ displayName: 'VideoMultiCaptionList', propTypes: { initialLocales: l.array.isRequired, localesMap: l.object.isRequired }, render: function () { if (this.props.initialLocales.length > 0) return (h.createElement('div', { className: "_3-8m" }, h.createElement('div', { className: "_439x _3-93 _3-8m" }, this.renderList()))); return (h.createElement('div', { className: "_3-8w" }, k._("No captions exist yet"))); }, renderList: function () { var p = this.props.initialLocales.map(function (q) { return (h.createElement(i, { deletekey: this.props.initialLocales.indexOf(q), key: n(q), locale: q, localeName: this.props.localesMap[q] })); }, this); return p; } }); f.exports = o; }, null);
__d('VideoMultiCaptionUploaderList.react', ['HelpLink.react', 'React', 'cx', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k) { if (c.__markCompiled) c.__markCompiled(); var l = 'captions_file', m = i.createClass({ displayName: 'VideoMultiCaptionUploaderList', render: function () { var n = i.createElement('div', { className: "_2c1z" }, k._("Valid SRT files must be used for captions. To replace an SRT file that is already being used for a locale, you must delete the old one first before uploading a new one.")); return (i.createElement('div', { className: "_3-8n _15z_" }, k._("Upload SRT files"), i.createElement(h, { tooltip: n, alignv: 'bottom' }), i.createElement('input', { 'aria-labelledby': 'metadata_caption', type: 'file', name: l }))); } }); f.exports = m; }, null);
__d('VideoMultiCaptionFileInput.react', ['React', 'VideoMultiCaptionDefaultSelector.react', 'VideoMultiCaptionList.react', 'VideoMultiCaptionUploaderList.react'], function a(b, c, d, e, f, g, h, i, j, k) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var l = h.PropTypes, m = h.createClass({ displayName: 'VideoMultiCaptionFileInput', propTypes: { defaultLocale: l.string, initialLocales: l.array.isRequired, localesMap: l.object.isRequired }, render: function () { var n = null; if (this.props.initialLocales.length) n = h.createElement(i, { defaultLocale: this.props.defaultLocale, locales: this.props.initialLocales, localesMap: this.props.localesMap }); return (h.createElement('div', null, h.createElement(j, { initialLocales: this.props.initialLocales, localesMap: this.props.localesMap }), n, h.createElement(k, null))); } }); f.exports = m; }, null);
__d('VideoEditCaptions.react', ['React', 'VideoMultiCaptionFileInput.react'], function a(b, c, d, e, f, g, h, i) { if (c.__markCompiled) c.__markCompiled(); var j = h.PropTypes, k = h.createClass({ displayName: 'VideoEditCaptions', propTypes: { captions: j.object }, getDefaultProps: function () { return { captions: [] }; }, render: function () { var l = this.props.captions, m, n = [], o = {}; for (var p in l) { var q = l[p]; if (q.is_default) m = q.locale; n.push(q.locale); o[q.locale] = q.locale_name; } return (h.createElement('div', { className: this.props.className }, h.createElement(i, { defaultLocale: m, initialLocales: n, localesMap: o }))); } }); f.exports = k; }, null);
__d('VideoEditMentionsTextArea.react', ['AtSignMentionsStrategy', 'DocumentCompositeMentionsSource', 'DocumentMentionsSource', 'EditorState', 'MentionsInput.react', 'MentionsInputUtility', 'MentionsInputTypeaheadView.react', 'React', 'cx', 'joinClasses', 'getMentionsInputDecorator'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) { if (c.__markCompiled) c.__markCompiled(); var s = o.PropTypes, t = o.createClass({ displayName: 'VideoEditMentionsTextArea', propTypes: { disabled: s.bool }, getDefaultProps: function () { return { disabled: false }; }, getInitialState: function () { var u = new j(h, this.props.searchSource), v = new i([u]), w = this.props.textWithMentions, x; if (this.props.editorState) { x = this.props.editorState; } else if (w) { x = m.createFromTextWithMentions(w, r()); } else x = k.createEmpty(r()); this.props.onChange(x); return { compositeMentionsSource: v, editorState: x }; }, _onChange: function (u) { if (this.props.disabled) return; this.setState({ editorState: u }); this.props.onChange(u); }, focus: function () { this.refs.mentionsInput.focus(); }, render: function () { var u = q("_2oc3", this.props.className); return (o.createElement(l, { className: u, editorState: this.state.editorState, mentionsSource: this.state.compositeMentionsSource, placeholder: this.props.placeholder, typeaheadView: n, typeaheadViewProps: {}, onChange: this._onChange, ref: 'mentionsInput' })); } }); f.exports = t; }, null);
__d('VideoEditTokenizer.react', ['React', 'XUITokenizer.react'], function a(b, c, d, e, f, g, h, i) { if (c.__markCompiled) c.__markCompiled(); var j = h.PropTypes, k = h.createClass({ displayName: 'VideoEditTokenizer', propTypes: { disabled: j.bool, onTagsChange: j.func.isRequired }, getDefaultProps: function () { return { disabled: false }; }, getInitialState: function () { return { queryString: '' }; }, onAddTagAttempt: function (l) { var m = this.props.entries || [], n = m.indexOf(l); if (n >= 0) return; m.push(l); this.props.onTagsChange(m); this.setState({ queryString: '' }); }, onRemoveTagAttempt: function (l) { var m = this.props.entries || [], n = m.indexOf(l); if (n >= 0) m.splice(n, 1); this.props.onTagsChange(m); }, onQueryStringChange: function (event) { if (this.props.disabled) { return; } else this.setState({ queryString: event.target.value }); }, render: function () { return (h.createElement(i, babelHelpers._extends({}, this.props, { onQueryStringChange: this.onQueryStringChange, queryString: this.state.queryString, onAddEntryAttempt: this.onAddTagAttempt, onRemoveEntryAttempt: this.onRemoveTagAttempt }))); } }); f.exports = k; }, null);
__d('VideoThumbnailPicker.react', ['AdsPEVideoThumbnailPicker.react', 'BUIFormButton.react', 'FileInput.react', 'Grid.react', 'React', 'cx', 'fbt'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n) { 'use strict'; if (c.__markCompiled) c.__markCompiled(); var o = k.GridItem, p = l.PropTypes, q = l.createClass({ displayName: 'VideoThumbnailPicker', propTypes: { thumbnails: p.arrayOf(p.shape({ id: p.string, uri: p.string.isRequired })).isRequired, onPickerChange: p.func.isRequired, index: p.number.isRequired, allowCustomThumbnails: p.bool.isRequired, onFileInputChange: p.func }, render: function () { var r = l.createElement(h, { thumbnails: this.props.thumbnails, onChange: this.props.onPickerChange, index: this.props.index, title: n._("Choose a Thumbnail") }), s; if (this.props.allowCustomThumbnails) { s = l.createElement(j, { accept: 'image/*', name: 'custom_thumbnail', onChange: this.props.onFileInputChange }, l.createElement(i, { href: { url: '#' }, label: n._("Add Custom Thumbnail") })); } else s = l.createElement('div', null); return (l.createElement(k, { cols: 2, spacing: 'prl' }, l.createElement(o, null, r), l.createElement(o, null, l.createElement('div', { className: "_5nd2" }, s)))); } }); f.exports = q; }, null);
__d('VideoEditForm.react', ['AdsAPIObjectives', 'AdsCreativeCallToActionField.react', 'AdsTypeahead.react', 'BUIForm.react', 'BUIFormButton.react', 'BUIFormTextInput.react', 'DOMContainer.react', 'FBNumberInput.react', 'InlineBlock.react', 'InputLabel.react', 'ProgressiveDateAndTimePicker.react', 'React', 'SearchableEntry', 'VideoEditCallToActionFields.react', 'VideoContentCategorySelector.react', 'VideoEditCaptions.react', 'VideoEditEvent', 'VideoEditFlow', 'VideoEditSource', 'VideoEditMentionsTextArea.react', 'VideoEditTokenizer.react', 'VideoEditTypedLogger', 'VideoThumbnailPicker.react', 'XUICheckboxInput.react', 'XUINotice.react', 'XUIText.react', 'cx', 'fbt', 'getMentionsTextForContentState'], function a(b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, aa, ba, ca, da, ea, fa, ga, ha, ia, ja) { if (c.__markCompiled) c.__markCompiled(); var ka = k.Element, la = k.Section, ma = s.PropTypes, na = b.URL || b.webkitURL || {}, oa = s.createClass({ displayName: 'VideoEditForm', propTypes: { allowCustomThumbnails: ma.bool, canBackdate: ma.bool, canFeature: ma.bool, canPreview: ma.bool, canTag: ma.bool, captions: ma.object, deleteDialogURI: ma.object, description: ma.string, embeddable: ma.bool, error: ma.object, fov: ma.number, initialHeading: ma.number, initialPitch: ma.number, isEncoding: ma.bool, isSpherical: ma.bool, locationEntry: ma.object, mentionsSearchSource: ma.object, notifyWhenProcessed: ma.bool, placesSearchSource: ma.object, preferredThumbnailIndex: ma.number, previewMarkup: ma.object, privacySelector: ma.object, privacyDescription: ma.string, source: ma.oneOf(Object.keys(z)), tags: ma.array, tagsSearchSource: ma.object, thumbnails: ma.array, title: ma.string, videoID: ma.string, videoPermalink: ma.string }, componentDidMount: function () { new ca().setEvent(x.JS_LOADED).setSource(this.props.source).setFlow(y.FORM).setVideoID(this.props.videoID).log(); }, getInitialState: function () { return { contentCategory: this.props.contentCategory, ctaType: this.props.ctaType, ctaLink: this.props.ctaLink, ctaCaption: this.props.ctaCaption, editorStateContent: this.props.description, fov: this.props.fov, initialHeading: this.props.initialHeading, initialPitch: this.props.initialPitch, locationEntry: this.props.locationEntry ? new t(this.props.locationEntry) : null, tags: this.props.tags || [], title: this.props.title, embeddable: this.props.embeddable, thumbnails: this.props.thumbnails, thumbnailIndex: this.props.preferredThumbnailIndex - 1 }; }, onTitleChange: function (event) { this.setState({ title: event.target.value }); }, onDescriptionChange: function (pa) { this.setState({ editorState: pa, editorStateContent: ja(pa.getCurrentContent()) }); }, onLocationSelectAtempt: function (pa) { this.setState({ locationEntry: pa }); }, getDateTimeKey: function (pa) { return 'initial' + pa.charAt(0).toUpperCase() + pa.slice(1); }, onTagsChange: function (pa) { this.setState({ tags: pa }); }, onThumbnailPickerChange: function (pa) { this.setState({ thumbnailIndex: pa }); }, onThumbnailImageChange: function (event) { if (typeof na.createObjectURL !== 'function') return; var pa, qa; if (event.target.files.length === 0) { pa = this.props.thumbnails; qa = this.state.thumbnailIndex >= pa.length ? pa.length - 1 : this.state.thumbnailIndex; } else { pa = this.props.thumbnails.concat([{ uri: na.createObjectURL(event.target.files[0]) }]); qa = pa.length - 1; } this.setState({ thumbnails: pa, thumbnailIndex: qa }); }, renderTaggerSection: function () { var pa = this.state.tags.map(function (ra) { return ra.getUniqueID(); }), qa = pa.join(','); return (s.createElement(la, { key: 'taggerSection' }, s.createElement(ka, { label: ia._("In this video"), infoText: ia._("Tag people who appear in this video.") }, s.createElement(ba, { className: "_2dlh", entries: this.state.tags, onTagsChange: this.onTagsChange, searchSource: this.props.tagsSearchSource }), s.createElement('input', { type: 'hidden', name: 'tags', value: qa })))); }, getPlaceInputKeyAndValue: function () { var pa = this.state.locationEntry, qa = 'place_id', ra = pa ? pa.getUniqueID() : null; if (pa && !ra) { qa = 'place_name'; ra = pa.getTitle(); } return { key: qa, value: ra }; }, renderDetailsSection: function () { var pa = this.getPlaceInputKeyAndValue(); return (s.createElement(la, { key: 'detailsSection' }, s.createElement(ka, { label: ia._("Title") }, s.createElement(m, { className: "_2dli", onChange: this.onTitleChange, value: this.state.title, name: 'title' })), this.renderThumbnailsFormElement(), s.createElement(ka, { label: ia._("Where") }, s.createElement(j, { className: "_32bi", autoHighlight: false, placeholder: ia._("Where was this video taken?"), selectedEntry: this.state.locationEntry, onSelectAttempt: this.onLocationSelectAtempt, searchSource: this.props.placesSearchSource }), s.createElement('input', { type: 'hidden', name: pa.key, value: pa.value })), this.renderBackdateFormElement(), s.createElement(ka, { label: ia._("Description") }, s.createElement(aa, { searchSource: this.props.mentionsSearchSource, className: "_3smg", editorState: this.state.editorState, textWithMentions: this.props.description, onChange: this.onDescriptionChange }), s.createElement('input', { type: 'hidden', name: 'description', value: this.state.editorStateContent })), this.renderCaptionsFormElement(), this.renderCallToActionFormElement(), this.renderEmbeddableFormElement(), this.renderSphericalVideoSection(), this.renderContentCategoryFormElement(), s.createElement(ka, { label: ia._("Privacy"), infoText: this.props.privacyDescription }, s.createElement(p, { className: "_32bj" }, s.createElement(n, null, this.props.privacySelector))))); }, renderBackdateFormElement: function () { if (!this.props.canBackdate) return s.createElement('div', null); var pa = {}; for (var qa in this.props.backdatedTime) { var ra = this.getDateTimeKey(qa); pa[ra] = parseInt(this.props.backdatedTime[qa], 10); } return (s.createElement(ka, { label: ia._("When") }, s.createElement(r, babelHelpers._extends({ className: "_32bj" }, pa, { inputPrefix: 'backtime', descendingYears: true })))); }, renderCaptionsFormElement: function () { return (s.createElement(ka, { label: ia._("Captions"), infoText: ia._("Upload your .SRT caption file using this format: filename.en_US.srt") }, s.createElement(w, { className: "_2dlj", captions: this.props.captions }))); }, renderThumbnailsFormElement: function () { if (this.props.isEncoding || this.state.thumbnails.length === 0) return s.createElement('div', null); var pa = s.createElement(da, { thumbnails: this.state.thumbnails, onPickerChange: this.onThumbnailPickerChange, index: this.state.thumbnailIndex, allowCustomThumbnails: this.props.allowCustomThumbnails, onFileInputChange: this.onThumbnailImageChange }); return (s.createElement(ka, { className: "_1q0n", label: ia._("Thumbnail") }, pa, s.createElement('input', { type: 'hidden', name: 'preferred_thumbnail_index', value: this.state.thumbnailIndex + 1 }))); }, onProhibitEmbeddableChange: function (event) { this.setState({ embeddable: !event.target.checked }); }, renderEmbeddableFormElement: function () { if (this.props.embeddable == null) return s.createElement('span', null); return (s.createElement(ka, { label: ia._("Embedding"), infoText: ia._("When checked, people cannot embed your video on third-party websites.") }, s.createElement(p, { className: "_32bj" }, s.createElement('input', { type: 'hidden', name: 'has_embeddable', value: 'true' }), s.createElement('input', { type: 'hidden', name: 'embeddable', value: this.state.embeddable }), s.createElement(q, { className: "_46oj" }, s.createElement(ea, { checked: !this.state.embeddable, onChange: this.onProhibitEmbeddableChange }), s.createElement('label', null, ia._("Prohibit embedding")))))); }, renderActionsSection: function () { return (s.createElement(la, { key: 'actionsSection' }, s.createElement('div', { className: "_59__ mvl" }, s.createElement(l, { href: this.props.videoPermalink, label: ia._("Cancel") }), s.createElement(l, { href: this.props.deleteDialogURI, label: ia._("Delete"), rel: 'dialog' }), s.createElement(l, { label: ia._("Save"), use: 'confirm' })))); }, renderCallToActionFormElement: function () { if (!this.props.isOwnerPage || this.props.hideCTA) return s.createElement('span', null); var pa = null; if (this.state.ctaType) pa = s.createElement(u, { ctaLink: this.state.ctaLink, ctaCaption: this.state.ctaCaption, onCtaLinkFieldChange: this._onCtaLinkFieldChange, onCtaCaptionFieldChange: this._onCtaCaptionFieldChange }); return (s.createElement(ka, { label: ia._("Call To Action") }, s.createElement('div', { className: "_3-95" }, ia._("Call-to-action buttons will appear after your video starts and will not appear in your preview.")), s.createElement(i, { apiObjective: h.VIDEO_VIEWS, onChange: this._onCtaTypeChange, selectedType: this.state.ctaType, noButtonLabel: ia._("No Button") }), s.createElement('input', { type: 'hidden', name: 'cta_type', value: this.state.ctaType }), pa)); }, _onCtaTypeChange: function (pa) { this.setState({ ctaType: pa.value }); }, _onCtaLinkFieldChange: function (pa) { this.setState({ ctaLink: pa }); }, _onCtaCaptionFieldChange: function (pa) { this.setState({ ctaCaption: pa }); }, renderContentCategoryFormElement: function () { return (s.createElement(ka, { label: ia._("Category"), infoText: ia._("Select a category that matches the content of your video") }, s.createElement('input', { type: 'hidden', name: 'content_category', value: this.state.contentCategory }), s.createElement(v, { onChange: this._onContentCategoryChange, value: this.state.contentCategory }))); }, _onContentCategoryChange: function (event) { this.setState({ contentCategory: event.value }); }, _onInitialHeadingChange: function (pa) { this.setState({ initialHeading: pa }); }, _onInitialPitchChange: function (pa) { this.setState({ initialPitch: pa }); }, _onFOVChange: function (pa) { this.setState({ fov: pa }); }, renderSphericalVideoSection: function () { if (!this.props.isSpherical) return s.createElement('span', null); return (s.createElement(ka, { label: ia._("360 Video") }, s.createElement(p, { className: "_32bj" }, s.createElement(q, null, s.createElement('label', { className: "_55r1 _58ak _4-nx" }, s.createElement(o, { name: 'initial_heading', value: this.state.initialHeading, defaultValue: 0, minValue: -180, maxValue: 180, onlyIntegers: true, onValueChange: this._onInitialHeadingChange, className: "_58al" })), s.createElement('label', null, s.createElement(ga, { weight: 'normal' }, ia._("Initial heading (-180\u00b0 to 180\u00b0)")))), s.createElement(q, null, s.createElement('label', { className: "_55r1 _58ak _4-nx" }, s.createElement(o, { name: 'initial_pitch', value: this.state.initialPitch, defaultValue: 0, minValue: -90, maxValue: 90, onlyIntegers: true, onValueChange: this._onInitialPitchChange, className: "_58al" })), s.createElement('label', null, s.createElement(ga, { weight: 'normal' }, ia._("Initial pitch (-90\u00b0 to 90\u00b0)")))), s.createElement(q, null, s.createElement('label', { className: "_55r1 _58ak _4-nx" }, s.createElement(o, { name: 'fov', value: this.state.fov, defaultValue: 60, minValue: 40, maxValue: 120, onlyIntegers: true, onValueChange: this._onFOVChange, className: "_58al" })), s.createElement('label', null, s.createElement(ga, { weight: 'normal' }, ia._("Vertical field of view (40\u00b0 to 120\u00b0)"))))))); }, renderError: function () { if (!this.props.error) return null; return (s.createElement(fa, { use: 'warn' }, s.createElement(n, null, this.props.error))); }, renderEncodingNotice: function () { if (!this.props.isEncoding) return null; return (s.createElement(fa, { use: 'notify' }, s.createElement('h1', null, ia._("This video is currently processing")), ia._("You can edit its details here, but you won't be able to choose a thumbnail until processing is complete."), s.createElement(q, null, s.createElement(ea, { name: 'alert_when_done', defaultChecked: this.props.notifyWhenProcessed }), s.createElement('label', null, ia._("Notify me when my video is done processing"))))); }, renderPreviewSection: function () { var pa = this.props.canFeature ? ia._("Feature") : ia._("Trailer"), qa = this.props.canFeature ? null : ia._("Mark this video as a trailer to have it show up as a preview for your page in various places on Facebook. You can only have one video marked as a trailer at a time."); return (s.createElement(la, { key: 'previewSection' }, s.createElement(ka, { label: pa, infoText: qa }, s.createElement(n, null, this.props.previewMarkup)))); }, render: function () { var pa = []; if (this.props.canTag) pa.push(this.renderTaggerSection()); pa.push(this.renderDetailsSection()); if (this.props.canFeature || this.props.canPreview) pa.push(this.renderPreviewSection()); pa.push(this.renderActionsSection()); return (s.createElement('div', null, this.renderError(), this.renderEncodingNotice(), s.createElement(k, { className: "_3slc" }, pa))); } }); f.exports = oa; }, null);